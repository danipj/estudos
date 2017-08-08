//Algum problema na fixUp (provavelmente) fazia printar na ordem: 5 - 4 - 3 - 2 - 0 - 1
//não consegui descobrir

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

/* Up heapify array from position x.
 * If a child has a higher priority than its parent,
 * swap them and call fixUp recursively on the parent.
 */
void fixUp(Heap * planes, int x){
    //printf("fix %s\n",planes->queue[x].key);
    //int i;
    if (planes->size < 2){
     //       for (i = 0; i < planes->size; ++i)
    //{
      //  printf("%s - ", planes->queue[i].key);
    //}
    //printf("\n");
    return;
    }
    if (parent(x)>-1){
        if (highest_priority(planes->queue[x],planes->queue[parent(x)])){
            swap(&planes->queue[x],&planes->queue[parent(x)]);

   // for (i = 0; i < planes->size; ++i)
    //{
     //   printf("%s - ", planes->queue[i].key);
    //}
    //printf("\n");
            fixUp(planes,parent(x));
        }
    }

}

/* Insert new plane in the priority queue.
 * If the size of the heap is equal to max_size, do nothing.
 * Don't forget to use the fixUp function.
 */
void insert_plane(Heap * planes, int max_size, char * key, int priority){
    if (planes->size == max_size)
        return;
    planes->size++;
    strcpy(planes->queue[planes->size-1].key,key);
    planes->queue[planes->size-1].priority = priority;
    fixUp(planes,planes->size-1);
}

/* Update the priorities of all landing planes by one.
 * Don't forget to use the fixUp function.
 */
void update_landing_priority(Heap * planes){
    int i;
    for (i = 0; i < planes->size; ++i)
    {
        //ve se aviao vai pousar
        if (planes->queue[i].key[0]=='L'){
            planes->queue[i].priority++;
        }
    }
    fixUp(planes,planes->size-1);
}

/* Down heapify array from position x.
 * If a child has a higher priority than its parent,
 * swap them and call fixDown recursively on the child.
 */
void fixDown(Heap * planes, int x){
    if (planes->size < 2)
        return;
    if(left_child(x)<planes->size)
        if (highest_priority(planes->queue[left_child(x)],planes->queue[x])){
            swap(&planes->queue[left_child(x)],&planes->queue[x]);
            fixDown(planes,left_child(x));
        }
}

//funcao pra remover
void remove_from_array(Heap *planes, int x){
    int i;
    for (i = x; i < planes->size-1; ++i)
    {
        planes->queue[i] = planes->queue[i+1];
    }
    planes->size--;
}

/* Get the plane of the highest priority and remove it from queue.
 * The result of the operation (key of the highest priority plane)
 * is to be stored in highest_priority_key.
 * Don't forget to use the fixDown function.
 */
void get_highest_priority(Heap * planes, char * highest_priority_key){
    //maior prioridade sempre estará no início da fila
    strcpy(highest_priority_key,planes->queue[0].key);
    remove_from_array(planes,0);
    if (planes->size > 1){
        fixDown(planes,0);
    }
}

/* Clear priority queue and free all allocated memory */
void clear(Heap * planees){
    free(planees);
}

int main(int argc, char const *argv[])
{
    char *chave = (char*) malloc(6 * sizeof(char));
    int i, prioridade, max, total;
    Heap *avioes = (Heap*) malloc(sizeof(Heap));
    avioes->size = 0;

    //ler maximo em fila
    scanf("%d",&max);
    avioes->queue = (Plane*) malloc (max*sizeof(Plane));

    while(scanf("%d",&total)!=EOF){
        if (total >0){
        //ler pares chave-prioridade
            for (i = 0; i < total; ++i)
            {
                scanf("%s %d",chave,&prioridade);
                insert_plane(avioes,max,chave,prioridade);
            }
        }

        if (avioes->size>0){
            //aumenta prioridade
            update_landing_priority(avioes);
            //pousa ou decola
            get_highest_priority(avioes,chave);
            //mostra a chave
            printf("%s",chave);
        }
        printf("\n");
    }
    clear(avioes);
    return 0;
}