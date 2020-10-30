a = int(input())
b = int(input())
s = 1
def sumD(s):
	ss=a
	  while ss>=10:
	  	su = 0
	  	while ss>0:
		    su+=ss%10
		    ss//=10
	  	ss = su
while a<=b:
  
  s*=ss
  a+=1
  while s>=10:
  	su = 0
  	while s>0:
	    su+=s%10
	    s//=10
  	s = su
  # print(s)
  if s==9:
    break
print(s)
 