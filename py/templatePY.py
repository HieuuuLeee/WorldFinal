import sys

# like the freopen in cpp
sys.stdin = open('in.txt','r')
sys.stdout = open('out.txt','w')

# input value
x = int(input())
x = bin(x)[0:]
print(x)
#output: 0b110100

ls = len(x)
print(len(x)[2:])
#output: 6

