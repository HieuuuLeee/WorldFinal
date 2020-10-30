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

const int inf = 1e5+5;

int a[inf],st[100001],n,t;

// int build(int n, int l, int r){
// 	if(l==r) return st[n]=1;
// 	if(l>r) return 0;
// 	st[n] = build(n*2,l,(l+r)/2) | build(n*2+1,(l+r)/2+1,r);
// 	return st[n];
// }
// int update(int n,int l,int r,int ql,int qr,int v){
// 	if(st[n]==0) return 0;
// 	if(l==r && l<=qr && l>=ql){
// 		if(l==v)return st[n]=1;
// 		else{
// 			a[l]=v;
// 			return st[n]=0;
// 		}
// 	}
// 	return st[n]=update(n*2,l,(l+r)/2,ql,qr,v) | update(n*2+1,(l+r)/2+1,r,ql,qr,v);
// }

int main(){
	// INFILE("../../in.txt");
	freopen("../../in.txt", "r", stdin);
	cin>>n>>t;
	cout<<n;
	// int tmp = build(1,1,n);
	// while(t--){
	// 	int x,y,z;
	// 	update(1,1,n,x,y,z);
	// }
	// For(i,1,n) cout<<a[i]<<" ";
}