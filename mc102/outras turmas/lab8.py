l = input()
matriz = []
while not l.isdigit():
	matriz.append(l.split())
	l = input()

# caça palavras criado e l contém número
palavras = []
for i in range(int(l)):
	p = input()
	palavras.append(p)

# lista de palavras criada, começar busca


linhas = len(matriz)
colunas = len(matriz[0])
matriz_saida = [["." for x in range(len(matriz[0]))] for y in range(len(matriz))]

def escreve(m):
	for linha in m:
		print(''.join(linha))

def armazena(matriz, palavra, coord, sentido):
	cont = 0
	while cont != len(palavra):
		matriz[coord[0]][coord[1]] = palavra[cont]
		cont+=1
		if sentido == 0:
			#horizontal frente
			coord[1] +=1
		elif sentido ==1:
			#horizontal tras
			coord[1]-=1
		elif sentido ==2:
			#vertical frente
			coord[0]+=1
		elif sentido ==3:
			#vertical tras
			coord[0]-=1
		elif sentido ==4:
			#nordeste
			coord[1]+=1
			coord[0]-=1
		elif sentido ==5:
			#sudeste
			coord[1]+=1
			coord[0]+=1
		elif sentido ==6:
			#noroste
			coord[1]-=1
			coord[0]-=1
		elif sentido ==7:
			#sudoeste
			coord[1]-=1
			coord[0]+=1
	return matriz

for k in range(int(l)):
	#procura por essa palavra
	encontrou = False
	for j in range(linhas):
		for i in range(colunas):
			if not encontrou:
				if matriz[j][i] == palavras[k][0]:
					
					#procura em todos os sentidos
					if i!= colunas-1:
						if matriz[j][i+1] == palavras[k][1]:
							# horizontal pra frente
							total = 2
							while total != len(palavras[k]) and total != 0 and i+total < colunas:
								if matriz[j][i+total] == palavras[k][total]:
									total += 1
								else:
									total = 0
									
							if total == len(palavras[k]):
								matriz_saida = armazena(matriz_saida,palavras[k],[j,i],0)
								encontrou = True
								break
						if j!=0 and matriz[j-1][i+1] == palavras[k][1]:
						# diagonal nordeste 
							total = 2
							while total != len(palavras[k]) and total != 0 and j-total >=0 and i+total < colunas:
								if matriz[j-total][i+total] == palavras[k][total]:
									total += 1
								else:
									total = 0
							if total == len(palavras[k]):
								matriz_saida = armazena(matriz_saida,palavras[k],[j,i],4)
								encontrou = True
								break
						if j!= linhas-1 and matriz[j+1][i+1] == palavras[k][1]:
							# diagonal sudeste
							total = 2
							while total != len(palavras[k]) and total != 0 and j+total < linhas and i+total < colunas:
								if matriz[j+total][i+total] == palavras[k][total]:
									total += 1
								else:
									total = 0
							if total == len(palavras[k]):
								matriz_saida = armazena(matriz_saida,palavras[k],[j,i],5)
								encontrou = True
								break
					
					if i!= 0:
						if matriz[j][i-1] == palavras[k][1]:
							# horizontal pra tras
							total = 2
							while total != len(palavras[k]) and total != 0 and i-total >= 0:
								if matriz[j][i-total] == palavras[k][total]:
									total += 1
								else:
									total = 0
							if total == len(palavras[k]):
								matriz_saida = armazena(matriz_saida,palavras[k],[j,i],1)
								encontrou = True
								break
							
						if j!=0 and matriz[j-1][i-1] == palavras[k][1]:
							# diagonal noroeste (ao contrario)
							total = 2
							while total != len(palavras[k]) and total != 0 and j-total >=0 and i-total >=0:
								if matriz[j-total][i-total] == palavras[k][total]:
									total += 1
								else:
									total = 0
							if total == len(palavras[k]):
								matriz_saida = armazena(matriz_saida,palavras[k],[j,i],6)
								encontrou = True
								break	
						
						if j!= linhas-1 and matriz[j+1][i-1] == palavras[k][1]:
							#diagonal sudoeste (ao contrario)
							total = 2
							while total != len(palavras[k]) and total != 0 and j+total < linhas and i-total >=0:
								if matriz[j+total][i-total] == palavras[k][total]:
									total += 1
								else:
									total = 0
							if total == len(palavras[k]):
								matriz_saida = armazena(matriz_saida,palavras[k],[j,i],7)
								encontrou = True
								break
						

					if j!= linhas-1 and matriz[j+1][i] == palavras[k][1]:
						# vertical para baixo
						total = 2
						while total != len(palavras[k]) and total != 0 and j+total < linhas:
							if matriz[j+total][i] == palavras[k][total]:
								total += 1
							else:
								total = 0
						if total == len(palavras[k]):
							matriz_saida = armazena(matriz_saida,palavras[k],[j,i],2)
							encontrou = True
							break
						
					if j!= 0 and matriz[j-1][i] == palavras[k][1]:
						# vertical para cima
						total = 2
						while total != len(palavras[k]) and total != 0 and j-total >=0:
							if matriz[j-total][i] == palavras[k][total]:
								total += 1
							else:
								total = 0
						if total == len(palavras[k]):
							matriz_saida = armazena(matriz_saida,palavras[k],[j,i],3)
							encontrou = True
							break
escreve(matriz_saida)						
					

