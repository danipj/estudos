/*
Daniela Palumbo
166301
lab transferências bancárias
*/
#define TRUE 1
#define FALSE 0

int main()
{
	int nroTransf, nroClientes, i, j,k,achou,contaOrig,contaDest,quantia;
	char nome[13][25], conta[13][17];
	float saldos[1000];
	char* str;

	scanf("%d %d",&nroClientes,&nroTransf);
	
	for (i = 0; i < nroClientes; ++i)
	{
		/*ler ate espaco*/
		scanf("%[^ ]s", str);
		/*ler espaco*/
		getchar();
		/*armazenar*/
		for (j = 0; str[j]!='\0'; ++j)
		{
			conta[i][j] = str[j];
		}
		/*marcar final da string*/
		conta[i][j] = '\0';

		/*ler nome ate achar numero*/
		scanf("%[^0-9]s", str);
		/*armazenar*/
		for (j = 0; str[j]!='\0'; ++j)
		{
			nome[i][j] = str[j];
		}
		/*marcar final da string*/
		nome[i][j] = '\0';
		
		/*ler saldo*/
		scanf("%f", &saldos[i]);
		/*saldos[i] = saldo;*/
	}

	for (i = 0; i < nroTransf; ++i)
	{

		contaOrig=-1;
		contaDest=-1;

		/*ler conta de origem*/
		scanf("%[^ ]s", str);
		/*procurar conta*/
		for (j=0; j < nroClientes && achou != TRUE; ++j)
		{
			achou = TRUE;
			for (k= 0; str[k]!='\0' && conta[k]!='\0' && achou == TRUE; ++k)
			{
				if (str[k]!=conta[k])
				{
					achou = FALSE;
				}
			}
		}
		if (achou == TRUE)
			contaOrig = j;
		
		scanf(" >> ");
		scanf("%f", &quantia);
		scanf(" >> ");
		
		/*ler conta de destino*/
		scanf("%[^\n]s", str);
		/*procurar conta*/
		for (j=0; j < nroClientes && achou != TRUE; ++j)
		{
			achou = TRUE;
			for (k= 0; str[k]!='\0' && conta[k]!='\0' && achou == TRUE; ++k)
			{
				if (str[k]!=conta[k])
				{
					achou = FALSE;
				}
			}
		}
		if (achou == TRUE)
			contaDest = j;
		
		if (contaOrig > -1 && contaDest > -1 && saldos[contaOrig]-quantia>=0){
			saldos[contaDest] += quantia;
			saldos[contaOrig] -= quantia;
		}
	}
	return 0;
}