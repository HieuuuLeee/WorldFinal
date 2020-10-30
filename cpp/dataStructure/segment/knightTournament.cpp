#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair

#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define Forl(i,a,b) for (ll i=a;i<=b;i++)
#define Fodl(i,b,a) for (ll i=b;i>=a;i--)

typedef int64_t ll;
typedef uint64_t ull;

#define prno                             cout<<"NO\n"
#define pryes                            cout<<"YES\n"
#define pryon                            pryes; else prno;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bitcount(n)         __builtin_popcountll(n)

#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)

const int inf = 1e6+5;

int a[inf],n,t;
vector<int> st (2000001,1);

int update(int n,int l,int r,int ql,int qr,int v){
	if(st[n]==0) return 0;
	if(l>qr||r<ql) return st[n];
	if(l==r && l<=qr && l>=ql){
		if(l==v)return st[n]=1;
		else{
			a[l]=v;
			return st[n]=0;
		}
	}
	return st[n]=update(n*2,l,(l+r)/2,ql,qr,v) | update(n*2+1,(l+r)/2+1,r,ql,qr,v);
}

int main(){
	cin>>n>>t;
// 	int tmp = build(1,1,n);
	while(t--){
		int x,y,z;
		cin>>x>>y>>z;
		update(1,1,n,x,y,z);
	}
	For(i,1,n) cout<<a[i]<<" ";
}