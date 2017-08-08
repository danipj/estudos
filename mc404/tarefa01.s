@ Daniela Palumbo 166301

	.org 0x1000 					@ programa comeca no endereco 0x1000 

start:
	set r1, 0x1000					@ cria um contador pra ler os caracteres comecando no endereco dado
	set r2, 0x2000					@ cria um contador pra percorrer a nova cadeia de caracteres
	set r3, 0x00 					@ cria um contador pra armazenar quantos caracteres foram lidos

while: 
	ldb r0, [r1]					@ le o byte no endereco e armazena no registrador
	stb [r2], r0					@ armazena o byte lido em outro endereco
	add r1, 0x1 					@ avanca a posicao na cadeia a copiar
	add r3, 0x1   					@ incrementa o contador de caracteres					
	cmp r0, 0x0   					@ compara se o lido foi zero
	jnz while						@ prossegue no laco
	set r1, 0x1000 					@ seta variaveis pra escrever nova cadeia 
	add r3, 0x1
	sub r2, 0x2 					@ volta dois espacos porque avanca antes da comparacao

new:
	ldb r0, [r2]					@ armazena o ultimo caractere na nova cadeia
	stb [r1], r0  					@ agora r2 e o primeiro caractere
    sub r3, 0x1   					@ decrementa os contadores
    sub r2, 0x1
    add r1, 0x1       				@ avanca na cadeia
    cmp r3, 0x0   					@ compara se a cadeia acabou
    jnz new	    					@ continua a copia caso ainda tenha caracteres
    
    hlt           					
