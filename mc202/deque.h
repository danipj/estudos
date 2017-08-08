/*
 * Pedro Tabacof - tabacof at gmail dot com
 * March 2016
 * Deques
 */

/* Deque implemented by a doubly linked list */
typedef struct deque {
	int x;
	struct deque *next, *prev;
} Deque;

/* Push element to the front of the deque */
void push_front(Deque **d_back, Deque **d_front, int x);

/* Push element to the back of the deque */
void push_back(Deque **d_back, Deque **d_front, int x);

/* Pop element of the front of the deque */
void pop_front(Deque **d_back, Deque **d_front);

/* Pop element of the back of the deque */
void pop_back(Deque **d_back, Deque **d_front);

/* Return value of the element at the front of the deque */
int front(Deque *d_front);

/* Return value of the element at the back of the deque */
int back(Deque *d_back);

/* Clear and frees memory of all elements of a deque */
void clear(Deque *d);

/* Print all elements in a deque
 * If given back of deque, print elements from back to front
 * If given front of deque, print elements from front to back
 */
void print(Deque *d);

