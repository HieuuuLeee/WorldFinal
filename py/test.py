import sys
import math

sys.stdin = open('in.txt','r')
sys.stdout = open('out.txt','w')

t = input()

n,k = t.split(' ')
n = int(n)
k = int(k)

res = 0
# a[0]:currNumber, a[1]:currSum, a[2]:currIndex

def check(a, i):
	if ((n-a[2]-1)>(k-a[1]-i)) | ((n-a[2]-1)*6<(k-a[1]-i)):
		return 0
	return 1

def bfs(a):
	ress = 0
	queue = []
	queue.append(a)
	while len(queue)!=0:
		s = queue.pop(0)
		if s[2]==n-1:
			ress += 1
		else:
			# print(s)
			for i in range(1,6):
				if check(s,i):
					queue.append([i,s[1]+i,s[2]+1])		
	return ress

if (n==1) & (k>=1) & (k<=6):
	res+=1
else:
	for i in range(1,6):
		if check([0,0,0],i)==1:
			res += bfs([i,i,1])

pro = res/(6**n)*100
print(format(pro, '.6f'))