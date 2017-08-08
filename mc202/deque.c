////Daniela Palumbo 166301

#include <deque.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	return 0;
}

Deque newDeque(int x){
	d = (Deque*) malloc(sizeof(Deque));
	d->next = NULL;
	d->prev = NULL;
	d->x = x;
	return d;
}

/* Push element to the front of the deque */
void push_front(Deque **d_back, Deque **d_front, int x){
	Deque* d = newDeque(x);
	d_front-> prev = d;
	d->next = d_front;
}

/* Push element to the back of the deque */
void push_back(Deque **d_back, Deque **d_front, int x){
	Deque* d = newDeque(x);
	d_back->next = d;
	d->prev = d_back;
}

/* Pop element of the front of the deque */
void pop_front(Deque **d_back, Deque **d_front){
	Deque* front = d_front->next;
	front->prev = NULL;
	free(d_front);
	d_front = front;
}

/* Pop element of the back of the deque */
void pop_back(Deque **d_back, Deque **d_front){
	Deque* back = d_back->prev;
	back->next = NULL;
	free(d_back);
	d_back = back;
} 

/* Return value of the element at the front of the deque */
int front(Deque *d_front){
	if (d_front==NULL)
		return 0;

	return d_front->x;
}

/* Return value of the element at the back of the deque */
int back(Deque *d_back){
	if (d_back==NULL)
		return 0;

	return d_back->x;
}

/* Clear and frees memory of all elements of a deque */
void clear(Deque *d){

}

/* Print all elements in a deque
 * If given back of deque, print elements from back to front
 * If given front of deque, print elements from front to back
 */
void print(Deque *d){
	if (d->prev == NULL){
		//se for front, imprime na ordem certa
		while(d->next!=NULL){
			printf("%d ",d->x);
			d = d->next;
		}
		printf("%d\n", d->x);
	} else {
		//imprime na ordem contraria
		while(d->prev!=NULL){
			printf("%d ",d->x);
			d = d->prev;
		}
		printf("%d\n", d->x);
	}
}