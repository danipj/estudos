/*
 * Pedro Tabacof - tabacof at gmail dot com
 * May 2016
 * Priority Queues using Max Heaps
 */

/* Data structures */

/* Plane node */
typedef struct plane {
    char key[5]; // First character: L for Landing and T for takeoff
    int priority;
} Plane;

/* Priority queue as max heap */
typedef struct heap {
    Plane * queue; // Array of planes that satisfy the heap property
    int size; // Current size of the array
} Heap;

/* Max Heap operations */
/* Their implementation and use is mandatory */

/* Up heapify array from position x.
 * If a child has a higher priority than its parent,
 * swap them and call fixUp recursively on the parent.
 */
void fixUp(Heap * planes, int x);

/* Insert new plane in the priority queue.
 * If the size of the heap is equal to max_size, do nothing.
 * Don't forget to use the fixUp function.
 */
void insert_plane(Heap * planes, int max_size, char * key, int priority);

/* Update the priorities of all landing planes by one.
 * Don't forget to use the fixUp function.
 */
void update_landing_priority(Heap * planes);

/* Down heapify array from position x.
 * If a child has a higher priority than its parent,
 * swap them and call fixDown recursively on the child.
 */
void fixDown(Heap * planes, int x);

/* Get the plane of the highest priority and remove it from queue.
 * The result of the operation (key of the highest priority plane)
 * is to be stored in highest_priority_key.
 * Don't forget to use the fixDown function.
 */
void get_highest_priority(Heap * planes, char * highest_priority_key);

/* Clear priority queue and free all allocated memory */
void clear(Heap * planees);

/* Helper functions */
/* Their use is not mandatory */

/* Return 1 (true) if plane A has higher priority than B and 0 (false) otherwise */
int highest_priority(Plane A, Plane B) {
  return (A.priority > B.priority) ||
         (A.priority == B.priority && strncmp(A.key, B.key, 5) < 0);
}

/* Swap planes A and B */
void swap(Plane * A, Plane * B) {
  Plane C = *B;
  *B = *A;
  *A = C;
}

/* Return left child of index x */
int left_child(int x) {
    return 2*x + 1;
}

/* Return right child of index x */
int right_child(int x) {
    return 2*x + 2;
}

/* Return parent of index x */
int parent(int x) {
    return (x - 1) / 2;
}