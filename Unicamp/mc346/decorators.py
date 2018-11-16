import time
class logstr:
   def __init__(self,f):
      self.f=f
      self.log=''
   def __call__(self,*args):
      self.log+=time.asctime()
      self.log+="entrada:"+str(args)
      x = self.f(*args)
      self.log+="saida:"+str(x)
      return self.f(*args)




   
def aux(x,y):
   return 2*x+y

xx=logstr(aux)
xx(3,4)

print(xx)
print(xx.log)
