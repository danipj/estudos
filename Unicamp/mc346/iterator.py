import random
class kesino:
   def __init__(self,x,k):
      self.k=k
      self.x=x
   def __iter__(self):
      return self
   def __next__(self):
   	  y = self.x.__next__()
   	  if random.randrange(self.k) == 0 :
	      return y

x = kesino(iter([2,3,3,5,1,3,6,1,54]),2)
print(x.__next__())
