# import sys

# # like the freopen in cpp
# sys.stdin = open('../in.txt','r')
# sys.stdout = open('../out.txt','w')

a,b,c,d = input().split()
# print(b)
a = int(a)
b = int(b)
c = int(c)
d = int(d)
k = b-d
if k==0:
  print("0 0")
  exit()
if k<0:
  ans1 = 1
  ans2 = 0
  while ans1*a-ans2*c!=(-k):
    while ans1*a-ans2*c<-k:
      ans1+=1
    while ans1*a-ans2*c>-k:
      ans2+=1
else:
  ans1 = 0
  ans2 = 1
  while -ans1*a+ans2*c!=(k):
    while -ans1*a+ans2*c<k:
      ans2+=1
    while -ans1*a+ans2*c>k:
      ans1+=1
print(str(ans1)+' '+str(ans2))