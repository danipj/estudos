@ 166301 Daniela Palumbo

init:
	set r1, 0x108		@ carrega vetor
	ld  r2, 0x100		@ carrega divisor
	ld  r3, 0x104		@ carrega num_elem
	set r0, 0x0 		@ zera soma

prep:
	mov r4, r2			@ copia divisor para manipular
	set r5, 0x0000FFFF	@ seta mascara para extrair elementos	
	ld  r6, [r1] 		@ carrega palavra
	and r5, r6 			@ aplica mascara
	shr r6, 0x10 		@ guarda outra palavra

div:
	shr r6, 0x1 		@ divide por 2
	shr r5, 0x1
	shr r4, 0x1 	
	cmp r4, 0x1 		@ verifica se ainda tem o que dividir
	jnz div 			

	add r0, r5			@ armazena o resultado da divisao
	sub r3, 0x1 		@ marca como elemento somado
	cmp r3, 0x0 		@ verifica se ainda tem o que somar
	jz end 				@ se nao, vai ao final do loop
	add r0, r6			@ soma segundo elemento 
	sub r3, 0x1 
	add r1, 0x4 		@ avanca no vetor

end:
	cmp r3, 0x0 		@ verifica se ainda tem o que somar
	jnz prep			@ se sim, volta ao comeco do loop

	hlt
						