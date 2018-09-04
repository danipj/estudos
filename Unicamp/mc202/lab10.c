#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* Create a decision tree */
TreeNode * createTree(int N, int P, Data * points){
    TreeNode *a = malloc(sizeof(TreeNode));
    Data *array1,*array0;
    int i,j,c1,c0;

    if (N==1){
        //criar folha
        a->decision = points[0].y;
        return a;
    }

    i=c1=c0=0;
    array1=malloc(N*sizeof(Data));
    array0=malloc(N*sizeof(Data));
    while(points[0].x[i]==-1)
        i++;
    for (j= 0; j < N; ++j)
    {
        //separa em vetor de sim e de nao
        if(points[j].x[i]==1){
            array1[c1]=points[j];
            c1++;
        } else if(points[j].x[i]==0){
            array0[c0]=points[j];
            c0++;
        }
        //"zera"
        points[j].x[i] = -1;
    }
    a->left = createTree(c0,P,array0);
    a->right = createTree(c1,P,array1);
    return a;
}

/* Predict a test point given a decision tree */
int predict(TreeNode * tree, Data test_point){
    //se for folha, retorna decisao
    if (tree->left==NULL&&tree->right==NULL){
        return tree->decision;
    }
    int i =0;
    //anda com os testes que ja foram
    while(test_point.x[i]==-1)
        i++;
    //anda na arvore
    if (test_point.x[i]==0){
        //"zera" o teste
        test_point.x[i] = -1;
        //segue
        predict(tree->left,test_point);
    } else {
        test_point.x[i] = -1;
        predict(tree->right,test_point);
    }
    return 0;
}

/* Clear decision tree */
void clearTree(TreeNode * tree){
    free(tree);
}

/* Clear array of points */
void clearData(int N, Data * points){
    int i;
    for (i = 0; i < N; ++i)
    {
        free(&points[i]);
    }
}

int main()
{
    int ptsTreinamento,preditores,i,j,qtsTestes;
    Data *dados,*dadosTeste;
    TreeNode *arv;

    scanf("%d %d",&ptsTreinamento,&preditores);

    dados = malloc(ptsTreinamento * sizeof(Data));
    dados->x = malloc(preditores * sizeof(int));
    dadosTeste = malloc(ptsTreinamento * sizeof(Data));

    for (i = 0; i < ptsTreinamento; ++i)
    {
        for (j = 0; j < preditores; ++j)
        {
            printf("what\n");
            scanf("%d ",&dados[i].x[j]);
        }
        //saida esperada
        scanf("%d ",&dados[i].y);
    }
    printf("alo\n");
    arv = createTree(ptsTreinamento,preditores,dados);

    scanf("%d",&qtsTestes);
    for (i = 0; i < qtsTestes; ++i)
    {
        for (j= 0; j < preditores; ++j)
        {
            scanf("%d",&dadosTeste[i].x[j]);
        }
        //calcula e mostra
        printf("%d\n", predict(arv,dadosTeste[i]));
    }
    clearTree(arv);
    clearData(ptsTreinamento,dados);
    return 0;
}