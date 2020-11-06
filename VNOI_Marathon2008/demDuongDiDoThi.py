import sys
# sys.stdin = open('../in.txt','r')
# sys.stdout = open('../out.txt','w')
n = int(input())
def factorial(n):
    res=1
    for i in range(1,n+1):
        res*=i
    return res
def nAk(n,k):
    return (factorial(n)//factorial(n-k))

nn=n-2
ans=1
for i in range(1,nn+1):
    ans += nAk(nn,i)
print(ans)