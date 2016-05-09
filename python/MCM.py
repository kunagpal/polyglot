from time import clock; from os import system
r,d,k,a,m,c,w=0,'',0,[30,35,15,5,10,20,25,30,35,15,5,10,20,25,30,35,15,5,10,20,25,30,35,15,5,10,20,25,30,35,15,5,10,20,25,30,35,15,5,10,20,25,30,35,15,5],[],0,[] #Place your matrix chain dimensions here. All other parameters are calculated automatically.
n=len(a)-1
def p(s,i=0,j=n-1):   # recursive method to determine optimal parentheses arrangement
 global d,k,r
 if i==j:
  d+=' '+str(i+1)+' '
  k+=1
  if k>=n: return
 else: 
  d+='('
  p(s,i,s[i][j]-1)
  p(s,s[i][j],j)
  d+=')'
d=n-3
for i in range(1,n):
 c+=a[0]*a[i]*a[i+1]    # un-optimized cost calculation
for i in range(n):
 m.append([])           # working matrix formation
 w.append([])
 for j in range(n):
  w[i].append(0)        # matrix initialization
  m[i].append(0)
i,j,k=0,1,0
start=clock()           # record starting timestamp
for v in range(n*(n-1)//2):
 s,l=m[i][i]+m[i+1][j]+a[i]*a[i+1]*a[j+1],i
 for k in range(i+1,j):
  #print(v+1,m[i][k],m[k+1][j],a[i]*a[k+1]*a[j+1])
  if (m[i][k]+m[k+1][j]+a[i]*a[k+1]*a[j+1])<s:    # optimal sub problem cost calculation
   s=m[i][k]+m[k+1][j]+a[i]*a[k+1]*a[j+1]
   l=k
 m[i][j]=s
 w[i][j]=l+1
 if j<n-1: 
  i+=1
  j+=1
 elif v==n*(n-1)//2-2: i=0 
 else:
   j-=d
   i=0
   d-=1
d=''   
p(w)                  # recursive method invoked here
end=clock()           # record ending timestamp
print(d)              # display optimal parentheses sequence
print('Optimized cost: ',m[0][n-1],'\nSavings: ',c-m[0][n-1],'\nComputation took: ',end-start,' seconds.') # Display additional information
system('pause')
