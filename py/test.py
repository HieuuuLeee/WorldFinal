a = []
a.append(2)
for i in range(1,36):
    sum,dem,cnt = 0,0,9;
    for j in range(i):
        cnt = 9*(10**(j//2))
        sum += cnt
    a.append(a[i-1]+sum)
t = int(input())
for i in range(t):
    n = int(input())
    print(a[n])
 