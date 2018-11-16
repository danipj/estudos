def benford(s):
    split = s.split(' ')
    
    final = []
    #preparo das palavras
    for x in split:
        
        n = x
        if '\n' in x:
            
            n = x.split('\n')
            for k in n:
                final.append(k)
        else:
            final.append(n)
        
    # contagem
    dic = {}
    nc = 0
    
    for x in final:
        
        if x[0].isdigit():
            print('uai')
            if x[0] in dic:
                dic[x[0]]+=1
            else:
                dic[x[0]]=1
            nc+=1
    for c in dic:
        print(c, ' = ', dic[c]/nc)

benford('abc 137.9 xyz\npalavra 33.8 4ever')
            
