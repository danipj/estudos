@166301 Daniela Palumbo

init:

@reservar espaco pra pilha
@iniciar reg apontador de pilha (sp)
set sp, 0x800

@funcao multiplica
multiplica:
	.skip 4

@ retorna valor dos 2 nros multiplicados em r0
@passagem de parametros por registrador

@funcao read 
@ le numero e "*"/"#" 
@ retorna em r0 o numero e em r1 o char (10/11)
@ teclado
%keyboard CalcPlus
0x80 0x81 0x00

read:
	@imaginando que o primeiro numero esta em r0 e o segundo em r1
	mov r2, r0 @salva primeiro numero
	mov r0, #0 @limpa r0
loop:
	add r0, r1 
	sub r2, 0x1
	cmp r2, 0x0
	jnz loop

@painel de 8 leds
%leds Resultado
rrrrrrrr 0x40
@ inicializar com o numero 1
@ usar multiplica pro numero corrente * numero do teclado e mudar no correte (logo, no painel)
ld r0, multiplica @recupera retorno da funcao
@ a tecla "#" indica fim das multiplicacoes 
hlt