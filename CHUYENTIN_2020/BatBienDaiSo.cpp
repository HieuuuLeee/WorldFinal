#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forl(i,a,b) for(ll i=a;i<=b;i++)
#define pb push_back

typedef int64_t ll;
string convert2string(int s);
int convert2INT(string s);
char cvtI2C(int c);
string convert(string s);
int cvt(char c);
void pre(string &s){
	int n = s.size();
	For(i,0,n-1){
	    switch(s[i]){
    		case('a'):
    			s[i]='A';
    			break;
    		case 'b':
    			s[i]='B';
    			break;
    		case 'c':
    			s[i]='C';
    			break;
    		case 'd':
    			s[i]='D';
    			break;
    		case 'e':
    			s[i]='E';
    			break;
    		case 'f':
    			s[i]='F';
    			break;
    		default:
    			break;
	    }
	}
}
char cvtI2C(int c){
	if(c>=0 && c<=9) return char(c+'0');
	return char(c-10+'A');
}
int cvt(char c){
	if(c-'0'>=0 && c-'0'<=9) return (c-'0');
	if(c-'a'>=0 && c-'a'<=5) return (c-'a'+10);
	return (c-'A'+10);
}

string convert(string s){
    int check = convert2INT(s);
	while(check>=16){
	    int n = s.size();
    	ll ans = 0;
    	For(i,0,n-1){
    		ans=(ans + cvt(s[i]))%16;
    	}
    	s = convert2string(ans);
	}
	return s;
}
int convert2INT(string s){
	int n = s.size();
	int res=0;
	For(i,0,n-1){
	   // cout<<"**:"<<cvt(s[i])<<"\n";
		res+=(pow(16,n-i-1)*cvt(s[i]));
	}
	return res;
}
string convert2string(int s){
	string res="";
	vector<char> ch;
	while(s>0){
		ch.pb(cvtI2C(s%16));
		s/=16;
	}

	for(int i = ch.size()-1;i>=0;i--) res+=ch[i];
	return res; 
}
// void gen()
int main(){
// 	freopen("in.txt","r",stdin);
// 	freopen("out.txt","w",stdout);
	string a,b;
	cin>>a>>b;
	pre(a); pre(b);
// 	cout<<a<<"\n"<<b<<"\n";
	int aa = convert2INT(a), bb = convert2INT(b);
	int res=1;
	For(i,aa,bb){
	   // res=convert2INT(convert(convert2string(res*i)));
		cout<<i<<": "<<convert2string(i)<<"\n";
	}
	cout<<res;
	// cout<<convert2string(30);
}