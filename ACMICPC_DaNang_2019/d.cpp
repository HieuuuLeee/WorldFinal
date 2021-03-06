#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair

#define For(i,a,b) for (int i=a;i<=b;++i)
#define Fod(i,b,a) for (int i=b;i>=a;--i)
#define Forl(i,a,b) for (ll i=a;i<=b;++i)
#define Fodl(i,b,a) for (ll i=b;i>=a;--i)

typedef int64_t ll;
typedef uint64_t ull;

#define prno                             cout<<"NO\n"
#define pryes                            cout<<"YES\n"
#define pryon                            pryes; else prno;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define prarr(a,n)            For(i,1,n)cout<<a[i]<<" "; brln;
#define bitcount(n)         __builtin_popcountll(n)

#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define fast              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll MOD = 1000000007;
const int MAX = 1000005;

int ans, t; 
int p,pp,ang,brut;
float h,hh;
char s;

float mod(float res){
	int ress = int(res);
	float ret;
	if(ang==90) ret = ress%180+(res-ress*1.0);
	else ret = ress%360+(res-ress*1.0);
	return ret;
}

int cvt(int i){
	return (i%60);
}

float cvtgio(int h, int i){
	return ((h+i/60)%12)*5+((i%60)*5.0/60);
}

float angle(int phut, float gio){
	if(phut>=gio) return (abs(gio-phut)*360.0/60);
	return ((phut+abs(60-gio))*360.0/60);
}

float f(int i, int h){
	int phut = cvt(i);
	float gio = cvtgio(h,i);
	return mod(angle(phut,gio));
}

int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    // cout<<"ssdfg";
    cin>>t;
    while(t--){
    	ans=0;
    	cin>>h>>s>>p>>hh>>s>>pp>>ang;
    	brut = (hh-h)*60-p+pp;
    	// cout<<brut<<"*\n";
    	if(f(p,h)==ang) ans++;
    	For(i,p+1,p+brut){
    		// cout<<f(i,h) <<" " <<f(i-1,h)<<"\n";
    		if(ang==0){if(f(i,h) < f(i-1,h)) ++ans;}
    		else {if(f(i,h)>=ang && f(i-1,h)<ang) ++ans;}
    	}
    	cout<<ans<<"\n";
    }
}