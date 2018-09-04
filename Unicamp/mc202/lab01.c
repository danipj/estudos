
/* Nome: Daniela Palumbo
* RA: 166301
* Laboratorio 01 - O problema do acesso à lista */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/* STRUCS, DEFINIÇÕES E CABEÇALHOS DAS SUAS FUNÇÕES DA TAD */
typedef struct no_lista_simples {
    int elem;
    struct no_lista_simples *prox;
} ListaSimples, NoListaSimples;

char ListaSimplesVazia(ListaSimples *inicio);
NoListaSimples *CriaNoSimples(int elem);
void ImprimeListaSimples(ListaSimples *inicio);
char BuscaElementoListaSimples(ListaSimples *inicio, int elem, NoListaSimples **pos, NoListaSimples **ant);
int acessaTR(ListaSimples *inicio, int elem, NoListaSimples **pos, NoListaSimples **ant);
int acessaMTF(ListaSimples *inicio, int elem, NoListaSimples **pos, NoListaSimples **ant);
char BuscaUltimoElementoListaSimples(ListaSimples *inicio, NoListaSimples **pos, NoListaSimples **ant);
void InsereInicioListaSimples(ListaSimples **inicio, int elem);
int InsereFimListaSimples(ListaSimples **inicio, int elem);
int InsereFimTR(ListaSimples **inicio, int elem);
char InsereElementoAntesDaChaveListaSimples(ListaSimples **inicio, int elem, int chave);
char RemoveInicioListaSimples(ListaSimples **inicio, int *elem);
int RemoveElementoListaSimples(ListaSimples **inicio, int elem);
char RemoveFimListaSimples(ListaSimples **inicio, int *elem);
void DestroiListaSimples(ListaSimples **inicio);
// assinatura de outras funções

/* SEU PROGRAMA - MAIN */
int main() {
    int tamLista, nroReq, aux, custoMTF, custoTR, i;
    ListaSimples *inicioMTF,*inicioTR;
    char req;
    //ler tamanho da lista e nro de requisicoes
    scanf("%d %d",&tamLista, &nroReq);

    //comeco da lista
    //scanf("%d",&aux);
    //inicioMTF = CriaNoSimples(aux);
   // inicioTR = CriaNoSimples(aux);
    custoTR=0;
    custoMTF=0;

    for (i = 0; i < tamLista; i++) {
      /* ler valor e armazenar na lista*/
      scanf("%d",&aux);
      InsereFimListaSimples(&inicioMTF, aux);
      InsereFimListaSimples(&inicioTR, aux);
    }
    NoListaSimples *pos, *ant;
    //ler requisicoes
    for (i = 0; i < nroReq; ++i)
    {
      scanf("%d %d",&req,&aux);
      switch(req){
        case 'a':
          custoTR += acessaTR(inicioTR,aux,&pos,&ant);
          custoMTF += acessaMTF(inicioMTF,aux,&pos,&ant);
          break;
        case 'i':
          custoMTF += InsereFimListaSimples(inicioMTF,aux);
          custoTR += InsereFimTR(inicioTR,aux);
          break;
        case 'r':
        custoTR += RemoveElementoListaSimples(inicioTR,aux);
        custoMTF += RemoveElementoListaSimples(inicioMTF,aux);
          break;
      }
    }
    printf("%d\n",custoMTF);
    ImprimeListaSimples(inicioMTF);
    printf("%d\n",custoTR);
    ImprimeListaSimples(inicioTR);
    return 0;
}

/* IMPLEMENTAÇÃO DAS FUNÇÕES DE SUA TAD */
char ListaSimplesVazia(ListaSimples *inicio)
{
  if (inicio == NULL) 
    return(1);
  else
    return(0);
}

void ImprimeListaSimples(ListaSimples *inicio)
{
  while (inicio != NULL) {
    printf("%d ",inicio->elem);
    inicio = inicio->prox;
  }
  printf("\n");
}

char BuscaElementoListaSimples(ListaSimples *inicio, int elem, NoListaSimples **pos, NoListaSimples **ant)
{
  *pos = inicio;
  *ant = NULL;

  while (((*pos) != NULL)&&((*pos)->elem != elem)){ /* busca o elemento */
    (*ant) = (*pos);
    (*pos) = (*pos)->prox;
  }
  if ((*pos) != NULL){ /* achou */
    return(1);
  } 

  return(0);
}

int acessaTR(ListaSimples *inicio, int elem, NoListaSimples **pos, NoListaSimples **ant)
{
  int count = 0;
  *pos = inicio;
  *ant = NULL;
  int aux;
  while (((*pos) != NULL)&&((*pos)->elem != elem)){ /* busca o elemento */
    count++;
    (*ant) = (*pos);
    (*pos) = (*pos)->prox;
  }
  if ((*pos) != NULL){ /* achou */
    //troca com o anterior
    if ((*ant)!=NULL){
      aux = (*ant)->elem;
      (*ant)->elem = (*pos)->elem;
      (*pos)->elem = aux;
      return(count+1);
    }else
    return(1);
  } 

  return(0);
}

int acessaMTF(ListaSimples *inicio, int elem, NoListaSimples **pos, NoListaSimples **ant)
{
  int count = 0;
  *pos = inicio;
  *ant = NULL;
  int aux;
  while (((*pos) != NULL)&&((*pos)->elem != elem)){ /* busca o elemento */
    count++;
    (*ant) = (*pos);
    (*pos) = (*pos)->prox;
  }
  if ((*pos) != NULL){ /* achou */
    //troca com o primeiro
    aux = (*inicio)->elem;
    (*inicio)->elem = (*pos)->elem;
    (*pos)->elem = aux;
    return(count);
  } 

  return(0);
}

char BuscaUltimoElementoListaSimples(ListaSimples *inicio, NoListaSimples **pos, NoListaSimples **ant){
  *pos = inicio;
  *ant = NULL;
  int count =0;
  if (ListaSimplesVazia(inicio))
    return(0);

  while (((*pos)->prox != NULL)){ /* busca o ultimo elemento */
    count++;
    (*ant) = (*pos);
    (*pos) = (*pos)->prox;
  }

  return(count);
}

NoListaSimples *CriaNoSimples(int elem)
{
  NoListaSimples *p = (NoListaSimples *)calloc(1,sizeof(NoListaSimples));
  p->elem = elem;
  p->prox = NULL;
  return(p);
}

void InsereInicioListaSimples(ListaSimples **inicio, int elem)
{
  NoListaSimples *p = CriaNoSimples(elem);

  p->prox = *inicio;
  *inicio =  p;
}

int InsereFimListaSimples(ListaSimples **inicio, int elem)
{
  NoListaSimples *p = CriaNoSimples(elem);
  NoListaSimples *pos, *ant;
  int count = BuscaUltimoElementoListaSimples(*inicio,&pos,&ant);
  if (count >0){
    pos->prox = p;
    return(count);
  } else { /* lista vazia */
    *inicio = p;
    return(0);
  }
}

int InsereFimTR(ListaSimples **inicio, int elem)
{
  NoListaSimples *p = CriaNoSimples(elem);
  NoListaSimples *pos, *ant;
  int count = BuscaUltimoElementoListaSimples(*inicio,&pos,&ant);
  if (count >0){
    //insere antes do ultimo
    ant->prox = p;
    return(count);
  } else { /* lista vazia */
    *inicio = p;
    return(0);
  }
}

char InsereElementoAntesDaChaveListaSimples(ListaSimples **inicio, int elem, int chave)
{
  NoListaSimples *pos, *ant;

  if(BuscaElementoListaSimples(*inicio, chave, &pos, &ant)){
    if (ant == NULL) { /* chave esta no inicio */
      InsereInicioListaSimples(inicio, elem);
    } else {
      InsereInicioListaSimples(&pos, elem);
      ant->prox = pos;
    }
    return(1);
  }
  
  return(0);
}

char  RemoveInicioListaSimples(ListaSimples **inicio, int *elem)
{
  NoListaSimples *p = *inicio;

  if (!ListaSimplesVazia(*inicio)){
    (*elem)   = (*inicio)->elem;
    (*inicio) = (*inicio)->prox; 
    free(p);
    return(1);
  }
 
  return(0);
}

int RemoveElementoListaSimples(ListaSimples **inicio, int elem)
{
  NoListaSimples *pos, *ant;
  int count = BuscaElementoListaSimples(*inicio,elem,&pos,&ant);
  if (count>0){ 
   RemoveInicioListaSimples(&pos,&elem);
    if (ant == NULL) 
      (*inicio) = pos;
    else
      ant->prox = pos;
    return(count);
  }
  
  return(0);
}

char  RemoveFimListaSimples(ListaSimples **inicio, int *elem)
{
  NoListaSimples *pos, *ant;

  if (BuscaUltimoElementoListaSimples(*inicio,&pos,&ant)){
    *elem = pos->elem;
    if (ant == NULL)
      (*inicio) = NULL;
    else
      ant->prox = pos->prox;
    free(pos);
    return(1);
  }

  return(0);
}

void DestroiListaSimples(ListaSimples **inicio)
{
  int elem;

  while (!ListaSimplesVazia(*inicio))
    RemoveInicioListaSimples(inicio,&elem);
}
