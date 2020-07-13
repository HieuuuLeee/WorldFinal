import sys
import math

sys.stdin = open('in.txt','r')
sys.stdout = open('out.txt','w')

t = sys.stdin.readline()

n,x,y = t.split(' ')
n = int(n)
x = int(x)
y = int(y)
if n<x:
	print(n)
	sys.exit()
res = x*y//math.gcd(x,y)	
# print(res)
ress = res
bu = ress//x + ress//y - 1
res -= bu
k = n//res
# print(res)
du = n-k*res
# print(du)
dem = x-1
if du==0:
	for i in range(k*ress-1,(k-1)*ress+1,-1):
		if ((i%x)!=0) & ((i%y)!=0):
			print(i)
			sys.exit()	

tx = 0
ty = 0
while (((du//x)!=tx) | ((du//y)!=ty)):
		while (du//x)!=tx:
			tmp = du//x
			du += (tmp-tx)
			tx = tmp
		while (du//y)!=ty:
			tmp = du//y
			du += (tmp-ty)
			ty = tmp
print(k*ress+du)