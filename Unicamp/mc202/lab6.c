#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
// Daniela Palumbo 166301

Dict* new_node(int key, char value[10]){
    Dict * node = (Dict*)malloc(sizeof(Dict));
    node->key = key;
    strcpy(node->value,value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

int is_empty(Dict* a)
{
 return a==NULL;
}

/* Insert key:value in dictionary. */
void insert_key_value(Dict **node, int key, char value[10]){
    if (is_empty(*node)){
        //arvore ainda n existe, criar
        *node = new_node(key,value);
    } else {
        if (key<(*node)->key){
            //se chave menor que chave atual e esquerda do atual nao eh vazia,
            //continuar a busca pela esquerda. se vazia, inserir
            if ((*node)->left!=NULL){
                insert_key_value(&(*node)->left,key,value);
            } else
                (*node)->left = new_node(key,value);
        } else if (key>(*node)->key){
            //repetir processo pra caso seja maior procurar na direita
            if ((*node)->right!=NULL){
                insert_key_value(&(*node)->right,key,value);
            } else
                (*node)->right = new_node(key,value);
        } else
            //chave igual a atual, sobrescrever valor
            strcpy((*node)->value,value);
    }
}

/* Remove key (and its corresponding value) from dictionary. */
void remove_key(Dict **node, int key){
    //encontrar chave
    if (!is_empty(*node)){
        if (key==(*node)->key){
            if ((*node)->left == NULL && (*node)->right == NULL) {
                free (*node);
                *node = NULL;
            } else if ((*node)->left == NULL){
                Dict* newNode = (*node);
                (*node) = (*node)->right;
                free (newNode);
            } else if ((*node)->right == NULL){
                Dict* newNode = (*node);
                (*node) = (*node)->left;
                free (newNode);
            } else {
                Dict* newNode = (*node)->left;
                while (newNode->right != NULL) {
                    newNode = newNode->right;
                }
                //troca
                (*node)->key = newNode->key;
                newNode->key = key;
                strcpy((*node)->value, newNode->value);
                //remove
                remove_key(&(*node)->left, key);
            }
        } else if (key<(*node)->key){
            //se menor esta na subarvore esquerda
                remove_key(&(*node)->left,key);
            }
            else{
                //se nao eh igual nem menor eh maior
                remove_key(&(*node)->right,key);
            }
    }
}

/* Get the value associated with given key.
 * Copy the return value to return_value. */
void get_value(Dict *node, int key, char return_value[10]){
    //seta valor de retorno como vazio, caso nao ache nao sera alterado
    strcpy(return_value,"");

    if(!is_empty(node)){ //se existe arvore
        if(node->key==key){
            strcpy(return_value,node->value);
        }else{
            if (key<node->key){
                //se menor procurar na subarvore esq, se nao na direita
                get_value(node->left,key,return_value);
            } else{
                get_value(node->right,key,return_value);
            }
        }
    }
}

/* Print all values ordered by their keys.
 * There must be spaces between the values and a newline at the end.
 * To make things easier, you may print a space between the last value and the newline. */
void ordered_print(Dict *node){
    //print infixo
    if (!is_empty(node)){
        ordered_print(node->left);
        printf("%s ",node->value);
        ordered_print(node->right);
    }
}

/* Clear tree and free all memory. */
void clear(Dict *node){
    if (!is_empty(node)){
        clear(node->left);
        clear(node->right);
        free(node);
    }
}

int main()
{
    char comando,string[10];
    Dict* dict=NULL;
    int key;

    while (scanf("%c ", &comando) != EOF) {
        switch(comando){
            case 'I':
                scanf("%d %s",&key,string);
                insert_key_value(&dict,key,string);
                break;
            case 'R':
                scanf("%d",&key);
                remove_key(&dict,key);
                break;
            case 'V':
                scanf("%d",&key);
                char string[10];
                get_value(dict,key,string);
                printf("%s\n",string);
                break;
            case 'P':
                ordered_print(dict);
                printf("\n");
                break;
        }
    }

    //fim da execucao, liberar memoria
    if(!is_empty(dict))
        clear(dict);

    return 0;
}