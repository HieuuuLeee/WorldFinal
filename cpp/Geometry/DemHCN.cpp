#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pp push
#define et empty
#define mp make_pair
#define count_array(a,b,n,indx) {int fiIndx=-1; for(int iiiii=0;iiiii<n;iiiii++) if(iiiii==n-1||(a[iiiii]!=a[iiiii+1])) {b[indx++]=iiiii-fiIndx; fiIndx=iiiii;}}
#define prefix_arr(a,b,n) {b[0]=a[0]; for(int iiiii=1;iiiii<n;iiiii++) b[iiiii]=b[iiiii-1]+a[iiiii];}
#define suffix_arr(a,b,n) {b[n-1]=a[n-1]; for(int iiiii=n-2;iiiii>=0;iiiii--) b[iiiii]=b[iiiii+1]+a[iiiii];}

#ifdef ONLINE_JUDGE
#define CURTIME()         ;
#define INFILE(name)      ;
#define OUFILE(name)      ;
#define DEBUG             ;
#define DUMP(value)       ;
#else
#define CURTIME()         cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define DEBUG             cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
#define DUMP(value)       cerr << "[" << (#value) << "]: " << (value) << el
#endif
#define For(i,aaaa,bbbb) for (int i=aaaa;i<bbbb;i++)
#define Fod(i,bbbb,aaaa) for (int i=bbbb;i>aaaa;i--)
typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

ll b[10000],c[10000];

ll C(ll m,ll n)
{
    if (n > m) return 0;
    ll re = 1;
    for(ll i = 1; i <= n; i++) re = re * (m - i + 1) / i;
    return re;
}

int main(){
	CURTIME();
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int n; cin>>n;
    ll a[n+1], j=0;
    For(i,0,n) cin>>a[i];
    sort(a, a+n);
	count_array(a, b, n, j)
	// For(i,0,j) cout<<b[i];
	ll res=0;
	For(i,0,n) if(b[i]>3) res+=C(b[i],4);
	For(i,0,n) b[i]=C(b[i],2);
	suffix_arr(b,c,n)
	For(i,0,n-1) res+=b[i]*c[i+1];
	cout<<res;
}