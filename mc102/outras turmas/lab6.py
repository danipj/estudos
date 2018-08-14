total = int(input())

if total > 100 or total < 1:
    print("Valor inválido na entrada.")
    total = 0


relatorio = {}

#armazenando os dados
for i in range(0,total):
    assassino, vitima, detetive = input().split()
    
    if assassino in relatorio:
        relatorio[assassino]['vitimas'].append(vitima)
    else:
        relatorio[assassino] = {'vida':True, 'vitimas':[vitima], 'casos':0}
        
    if detetive in relatorio:
        relatorio[detetive]['casos'] += 1
    else:
        relatorio[detetive] = {'vida':True, 'vitimas':[], 'casos':1}
        
    if vitima in relatorio:
        relatorio[vitima]['vida'] = False
    else:
        relatorio[vitima] = {'vida':False, 'vitimas':[], 'casos':0}

#deixar bonito pra escrever rápido
vitimastr = 'vítima inocente.'
assasstr = 'assassino(a).'
detetivestr = 'detetive.'

#descobrir se pessoa é detetive ou assassino
for pessoa in relatorio:
    categoria = vitimastr
    if relatorio[pessoa]['casos']>0:
        categoria = detetivestr
    elif len(relatorio[pessoa]['vitimas']) >0:
        categoria = assasstr

    relatorio[pessoa]['categoria'] = categoria

# compilando os dados
for pessoa in sorted(relatorio):
    print(60 * '-')

    #descobrir se pessoa morreu
    morto = ''
    if not relatorio[pessoa]['vida']:
        morto = ' (in memoriam)'

    #escrever
    print(pessoa + morto + ': ' + relatorio[pessoa]['categoria'])

    #escrever casos resolvidos se for detetive
    if relatorio[pessoa]['casos']>0:
        print('  Resolveu '+ str(relatorio[pessoa]['casos']) + ' caso(s).')

    #contabilizar mortes por categoria
    mortes = {vitimastr:0,assasstr: 0,detetivestr:0}
    for vitima in relatorio[pessoa]['vitimas']:
        mortes[relatorio[vitima]['categoria']] += 1

    #escrever mortes
    if mortes[detetivestr]>0:
        print('  Matou '+str(mortes[detetivestr]) + ' detetive(s).')
    if mortes[assasstr]>0:
        print('  Matou '+str(mortes[assasstr]) + ' assassino(s).')
    if mortes[vitimastr]>0:
        print('  Matou '+str(mortes[vitimastr]) + ' inocente(s).')
        
        
    


if total > 0:    
    print (60*'-')
