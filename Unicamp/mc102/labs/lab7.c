#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareString(char * a, char * b)
{
    return strcmp(a, b);
}

int compareInt(char * a, char * b)
{
    return 0;
}

void merge(char v[], char aux[], int inicio1, int inicio2, int fim2, int (* compare)(char * a, char * b)) {

    int i = inicio1, j = inicio2, fim1 = inicio2 - 1, k = 0;

    /* Enquanto existirem elementos nas duas partes...*/
    while ((i <= fim1) && (j <= fim2))

    /* ... verifica qual dos dois elementos iniciais eh o menor */
    if (compare(&v[i], &v[j]) < 0)
        aux[k++] = v[i++]; /* ou copia o elemento inicial da primeira parte */
    else
        aux[k++] = v[j++]; /* ou copia o elemento inicial da segunda parte */

    while (i <= fim1) /* Se ainda existir elementos na primeira parte ... */
        aux[k++] = v[i++]; /* ... copia os elementos restantes no vetor auxiliar */

    while (j <= fim2) /* Se ainda existir elementos na segunda parte ... */
        aux[k++] = v[j++]; /* ... copia os elementos restantes no vetor auxiliar */

    for (i = 0; i < k; i++) /* Copia os elementos do vetor auxiliar ... */
        v[i + inicio1] = aux[i]; /* ... de volta para o vetor original */
}

void mergesort(char ** array, int N, int (* compare)(char * a, char * b))
{
    char * aux = (char*) malloc(N * sizeof(char));

    mergeSortAux(array, aux, 0, N - 1);
}

void mergeSortAux(char v[], char aux[], int inicio, int fim, int (* compare)(char * a, char * b)) {

    int meio = (inicio + fim) / 2;

    /* Se existirem pelo menos dois elementos para serem ordenados... */
    if (inicio < fim)
    {
        mergesort(v, aux, inicio, meio, &compare); /* Ordena a primeira parte */
        mergesort(v, aux, meio + 1, fim, &compare); /* Ordena a segunda parte */
        merge(v, aux, inicio, meio + 1, fim, &compare); /* Intercala as duas partes */
    }
}

void quickSort(char ** array, int N, int (* compare)(char * a, char * b))
{

}

void removeSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

int main(void) {

    char sort, type;
    char * string = (char*) malloc(20 * sizeof(char)); // init array

    scanf("%c %c ", &sort, &type); // read settings

    fgets(string, 20, stdin); // read array

    removeSpaces(string); // remove spaces

    if (sort == 'Q')
    {
        if (type == 'I')
        {

        }
        else // type ´== 'S'
        {

        }
    }
    else // sort == 'M'
    {
        if (type == 'I')
        {

        }
        else // type == 'S'
        {
            mergeSort(&string, strlen(string), &compareString);
        }
    }

    return 0;
}

