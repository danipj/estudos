/* Nome: Daniela Palumbo
 * RA: 166301
 * Laboratorio 05 - Calculadora Pseudocientífica */

typedef struct noarvore
{
    int value;
    noarvore esq;
    noarvore dir;
} NoArvore;

int calcular(NoArvore* n);
NoArvore* criaArvore(char* s, int inicio, int fim);
NoArvore* novoNo(int value, NoArvore* noEsq, NoArvore* noDir);

int main()
{
    char* expressao;
    int qtsChar = 0;

    //le a expressao
    scanf('%s',expressao);

    //conta tamanho da string
    for (qtsChar = 0; expressao[qtsChar]!='\0'; ++qtsChar);
    NoArvore no = criaArvore(expressao,0,qtsChar);

    return 0;
}

int calcular(NoArvore* n){
    //se for um numero, retorna para que o no pai faca a operacao
    if (n->value>0)
        return n->value;

    //se for uma operacao, retorna o resultado dos filhos
    switch(n->value)
        case -1:
            return calcular(n->esq) + calcular(n->dir);
            break;
        case -2:
            return calcular(n->esq) - calcular(n->dir);
            break;
        case -3:
            return calcular(n->esq) * calcular(n->dir);
            break;
        case -4:
            return calcular(n->esq) / calcular(n->dir);
            break;
    }
}

NoArvore* criaArvore(char* s, int inicio, int fim){
    if (fim-inicio==1)
    //substring que so tem parenteses
        return NULL;

    int contaParenteses = 0;
    int i = fim;
    int operacao = 0;
    int value;

    //busca final dos parenteses pra achar no pai
    do{
        if (s[i]==')')
        {
            contaParenteses++;
        } else if (s[i]=='(')
        {
            contaParenteses--;
        }
        i--;

    } while(contaParenteses>0);

    if (contaParenteses==0)
    {
        value = s[i];
        //verifica se eh operacao
        if (s[i-1]=='-')
        {
            value = value*-1;
            //pra ignorar na substring
            operacao = 1;
        }
        //achou o no pai, criar subarvore esquerda e direita recursivamente
        return novoNo(value, criaArvore(s,inicio+1,i-operacao-1),criaArvore(s,i+1,fim-1));
    }
}

NoArvore* novoNo(int value, NoArvore* noEsq, NoArvore* noDir){
    NoArvore* no = (NoArvore*) malloc(sizeof (NoArvore));
    no->value = value;
    no->esq = noEsq;
    no->dir = noDir;
    return no;
}