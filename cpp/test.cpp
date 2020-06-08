#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pp push
#define et empty
#define mp make_pair

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
#define For(i,a,b) for (int i=a;i<b;i++)
#define Fod(i,b,a) for (int i=b;i>a;i--)
#define Forl(i,a,b) for (ll i=a;i<b;i++)
#define Fodl(i,b,a) for (ll i=b;i>a;i--)
#define ForV(v) for (auto it = v.begin(); it!=v.end(); ++it)
typedef int64_t ll;
typedef uint64_t ull;
#define prno                             cout<<"NO\n"
#define pryes                            cout<<"YES\n"
#define pryon                            pryes; else prno;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)
ll tmp,t,n,a[555],b[555];
int main(){
    CURTIME();
    INFILE("in.txt");
    OUFILE("out.txt");
    cin>>t;
    while(t--){
        int poss=1; cin>>n;
        For(i,0,n) cin>>a[i];
        For(i,0,n) cin>>b[i];
        if(n%2 && a[n/2]!=b[n/2]) poss = 0;
        map<pair<ll,ll>,int> m;
        For(i,0,n/2) {
            m[mp(min(a[i],a[n-1-i]),max(a[i],a[n-1-i]))]++;
        }
        For(i,0,n/2) {
            if(m[mp(min(b[i],b[n-1-i]),max(b[i],b[n-1-i]))]<=0) poss=0;
            m[mp(min(b[i],b[n-1-i]),max(b[i],b[n-1-i]))]--;
        }
        if(poss) pryon;
    }
}