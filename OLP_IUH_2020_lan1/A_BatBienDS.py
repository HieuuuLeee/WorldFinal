# import sys
# sys.stdin = open('../in.txt','r')
# sys.stdout = open('../out.txt','w')
def f(a):
	if a==0:
		return 0
	else:
		return (a+14)%15+1

a = int(input(), 16)
b = int(input(), 16)

if (a == 0):
    print(0)
    exit(0)

if (b - a >= 6):
    print('F')
    exit(0)

ans = 1
for i in range(a, b + 1):
    ans *= f(i)
    ans = f(ans)
print(hex(ans)[-1].upper())