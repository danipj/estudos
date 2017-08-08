/*
 * Pedro Tabacof - tabacof at gmail dot com
 * May 2016
 * Decision tree
 */

#include <stdlib.h>
#include <math.h>
#include <float.h>

// Decision tree as binary tree
typedef struct treeNode {
    int decision;
    struct treeNode * left, * right;
} TreeNode;

typedef struct data {
  int *x; // Features
  int y; // Output
} Data;

/* Create a decision tree */
TreeNode * createTree(int N, int P, Data * points);

/* Predict a test point given a decision tree */
int predict(TreeNode * tree, Data test_point);

/* Clear decision tree */
void clearTree(TreeNode * tree);

/* Clear array of points */
void clearData(int N, Data * points);

/* Returns the feature with maximum information gain
 * The feature is an integer from 0 to P-1
 * Features with -1 values will be ignored
 */
int maxInformationGain(int N, int P, Data * points) {
  // Based on https://en.wikipedia.org/wiki/ID3_algorithm#The_ID3_metrics

  // Whole set entropy
  double p = 0.0;
  for (int i = 0; i < N; i++) p += points[i].y;
  p /= N;
  double entropy = -(p*log2(p) + (1.0-p)*log2(1.0-p));
  double * informationGain = (double *)malloc(sizeof(double)*P);

  for (int i = 0; i < P; i++) {
    // Skip -1 features
    if (points[0].x[i] == -1) {
      informationGain[i] = -DBL_MAX;
      continue;
    }

    // Feature division entropy
    double proportion = 0.0;
    double p0 = 0.0, p1 = 0.0;
    for (int j = 0; j < N; j++) {
      proportion +=  points[j].x[i];
      if (points[j].x[i]) p1 += points[j].y;
      else p0 += points[j].y;
    }
    proportion /= N;
    p1 /= N;
    p0 /= N;

    // Entropy of set with feature = 0
    double entropy0 = -(p0*log2(p0) + (1.0-p0)*log2(1.0-p0));
    if (p0 <= 0.0 || p0 >= 1.0) entropy0 = 0.0;

    // Entropy of set with feature = 1
    double entropy1 = -(p1*log2(p1) + (1.0-p1)*log2(1.0-p1));
    if (p1 <= 0.0 || p1 >= 1.0) entropy1 = 0.0;

    // Information gain
    informationGain[i] = entropy - (proportion*entropy1 + (1.0-proportion)*entropy0);
  }

  // Find feature with largest information gain
  double maxGain = -DBL_MAX;
  int maxInfoGain = 0;

  for (int i = 0; i < P; i++) {
    if (informationGain[i] > maxGain) {
      maxGain = informationGain[i];
      maxInfoGain = i;
    }
  }

  free(informationGain);
  return maxInfoGain;
}