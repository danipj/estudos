/* Daniel Costa
169405
Lab Semanal 05*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct data{
    int dia, mes, ano;
}Data;

typedef struct pessoa{
    char* nome;
    Data* dataNasc;
    char genero, preferencia;
    int* notas;
}Pessoa;

typedef struct aresta{
    Pessoa *vertice1, *vertice2;
    float peso;
}Aresta;

Aresta *novaAresta(Pessoa *v1, Pessoa *v2, float p){
    Aresta* a = (Aresta*) malloc(sizeof(Aresta));
    a->vertice1=v1;
    a->vertice2=v2;
    a->peso=p;
    return a;
}

Pessoa *novaPessoa(char* n, Data* dn, char g, char pref, int* notas, int tamanho){
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    p->nome = (char*) malloc(800*sizeof(char));
    strcpy(p->nome,n);
    //p->nome=n;
    p->dataNasc=dn;
    p->genero=g;
    p->preferencia=pref;
    p->notas = notas;
    return p;
}

Data *novaData(int d, int m, int a){
    Data *data = (Data*) malloc(sizeof(Data));
    data->dia=d;
    data->mes=m;
    data->ano=a;
    return data;
}

int contaArestas(Pessoa *p){
    int total;
    for(total=0;&p->notas[total]!=NULL;total++);
    return total-1;
}

float pesoAresta(Pessoa *pessoas, int i, int j){
    double mult = pessoas[i].notas[j]*pessoas[j].notas[i];
    return sqrt(mult);
}

char* soundex(char* nome){
    char* result = (char*) malloc(5*sizeof(char));
    result[0] = nome[0];
    int i,j,total=1;
    char* nomeAtual = (char*) malloc(800*sizeof(char));
    strcpy(nomeAtual,nome);
    //so considerar primeiro nome
    for (i = 0; nomeAtual[i]!=' '; ++i);
    //forcar final da string
    nomeAtual[i]='\0';
    // verificar letras duplicadas
    for (i = 0; nomeAtual[i]!='\0'; ++i)
    {
        //comeca na proxima
        for (j = i+1; nomeAtual[j]!='\0'; ++j)
        {
            //letras duplicadas devem ser ignoradas.
            //vogais devem ser ignoradas. transformar duplicada em vogal
            //para ignorar no switch
            if (nomeAtual[j]==nomeAtual[i]){
                   nomeAtual[j]='a';
            }
        }
    }
    for (i = 1; nomeAtual[i]!='\0'; ++i)
    {
        if (total<=3){
            switch(tolower(nomeAtual[i])){
                case 'g':
                case 'j':
                    result[total]= '1';
                    total++;
                    break;
                case 's':
                case 'z':
                case 'x':
                    result[total]= '2';
                    total++;
                    break;
                case 'c':
                case 'k':
                case 'q':
                    result[total]= '3';
                    total++;
                    break;
                case 'b':
                case 'p':
                    result[total]= '4';
                    total++;
                    break;
                case 'm':
                case 'n':
                    result[total]= '5';
                    total++;
                    break;
                case 'd':
                case 't':
                    result[total]= '6';
                    total++;
                    break;
                case 'f':
                case 'v':
                    result[total]= '7';
                    total++;
                    break;
                case 'l':
                    result[total]= '8';
                    total++;
                    break;
                case 'r':
                    result[total]= '9';
                    total++;
                    break;
                default:
                    //vogal = nao faz nada
                    break;
            }
        }
    }
    //caso o nome seja curto, completa com zero
    if (total<=3){
        for (i = total; i <= 3; ++i)
        {
            result[i]='0';
        }
    }
    return result;
}

int numerologia(Data *nasc){
    int total = nasc->dia+nasc->mes;
    int totalAno = 0;
    int ano = nasc->ano;
    //soma digitos ano
    while(ano>0){
        totalAno += ano%10;
        ano = ano/10;
    }
    total+=totalAno;
    //enquanto tiver 2 digitos
    while(total>9){
        ano = total;
        total =0;
        while(ano>0){
            total += ano%10;
            ano = ano/10;
        }
    }
    return total;
}

char* numerologiaPessoa(Pessoa *p,Data *dataAtual){
    char* result = (char*) malloc(4*sizeof(char));
    //+48 transforma em char do nro pela ascii table
    result[0] = numerologia(p->dataNasc)+48;
    int idade = dataAtual->ano - p->dataNasc->ano;
    //verificar se ainda nao fez aniversario
    if(dataAtual->mes < p->dataNasc->mes){
            idade--;
    } else if (dataAtual->mes == p->dataNasc->mes){
        if (dataAtual->dia < p->dataNasc->dia){
            idade--;
        }
    }
    //transformar em string
    if (idade>9){
        //considerar só 2 primeiros digitos
        result[1]=idade/10+48;
        result[2]=idade%10+48;
    } else {
        result[1]=idade+48;
        result[2]='0';
    }
    return result;
}

float similaridade(char* s1, char* s2,int tamanho){
    int i;
    float total = 0;
    for (i = 0; i< tamanho; ++i)
    {
        if (s1[i]==s2[i]){
            total+=1/(double)tamanho;
        }
    }
    return total;
}

float sintonia(Pessoa *pessoas,int i,int j,Data *dataAtual){
    return (3*similaridade(soundex(pessoas[i].nome),soundex(pessoas[j].nome),4)+5*similaridade(numerologiaPessoa(&pessoas[i],dataAtual),numerologiaPessoa(&pessoas[j],dataAtual),3)+(2*pesoAresta(pessoas,i,j)/(double)10))/(double)10;
}

int main()
{
    int dia,mes,ano,diaAluno,mesAluno,anoAluno,totalAlunos,*notasAluno,i,j,maior,alunoPopular,totalArestas;
    float peso,sintoniaAtual,maiorSintonia;
    char genero,preferencia,*nomeAluno = (char*) malloc(800*sizeof(char));
    Data* dataAtual;

    scanf("%d/%d/%d%*c",&dia,&mes,&ano);
    dataAtual = novaData(dia,mes,ano);

    scanf("%d%*c",&totalAlunos);

    Pessoa* alunos = (Pessoa*) malloc(totalAlunos*sizeof(Pessoa));
    int *popularidade = (int*) calloc(totalAlunos,sizeof(int));

    //leitura dos formularios
    for (i = 0; i < totalAlunos; ++i)
    {
        fgets(nomeAluno,800,stdin);
        //remover \n do nome
        nomeAluno[strlen(nomeAluno)-1]='\0';
        //scanf(" %[^\n]s",nomeAluno);
        scanf("%d/%d/%d%*c",&diaAluno,&mesAluno,&anoAluno);
        scanf(" %c %c ",&genero,&preferencia);
        notasAluno = (int*) malloc(totalAlunos*sizeof(int));
        for (j = 0; j < totalAlunos; ++j)
        {
            if(j!=i){ //aluno nao da nota a si mesmo
                scanf("%d%*c",&notasAluno[j]);
            }
        }
        alunos[i] = *novaPessoa(nomeAluno,novaData(diaAluno,mesAluno,anoAluno),genero,preferencia,notasAluno,totalAlunos);
    }

    //max possivel de arestas seria total*(total-1) ja que nao se da nota a si mesmo
    Aresta *arestas = (Aresta*) malloc(totalAlunos*(totalAlunos-1)*sizeof(Aresta));
    totalArestas = 0;
    //criar arestas entre pessoas
    for (i = 0; i < totalAlunos; ++i)
    {
        //comeca em i+1 pois nao existe nota de i para i e
        //sempre ja vai ter verificado os valores anteriores.
        //logo, i+1 elimina arestas duplicadas
        for (j= i+1; j < totalAlunos; ++j)
        {
            peso = pesoAresta(alunos,i,j);
            if (peso>=5){
                arestas[totalArestas] = *novaAresta(&alunos[i],&alunos[j],peso);
                totalArestas++;
                //vetor popularidade incrementa os indices dos alunos que agora tem uma aresta
                popularidade[i]++;
                popularidade[j]++;
            }
        }
    }
    //descobrir mais popular
    maior =0;
    for (i = 0; i < totalAlunos; ++i)
    {
        if (popularidade[i]>maior){
            maior = popularidade[i];
            alunoPopular = i;
        }
    }
    //descobrir quem tem mais sintonia com essa pessoa
    maior=0;
    maiorSintonia=0;
    for (i = 0; i < totalAlunos; ++i)
    {
        if (alunos[alunoPopular].preferencia==alunos[i].genero && i!=alunoPopular){
            sintoniaAtual = sintonia(alunos,alunoPopular,i,dataAtual);
            if (sintoniaAtual>maior){
                maiorSintonia = sintoniaAtual;
                maior = i;
            }
        }
    }

    printf("%s combina com %s com %.2f de sintonia s2\n",alunos[alunoPopular].nome,alunos[maior].nome,maiorSintonia);
    return 0;
}