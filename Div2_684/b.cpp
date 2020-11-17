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

long long ans;
int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    int t;
    cin>>t; //cout<<t;
    while(t--){
        int n,k; 
        cin>>n>>k;
        ll a[n*k+5];
        ll ans=0;
        For(i,0,n*k-1) cin>>a[i];
        sort(a,a+n*k);
        // prarr(a,n*k-1);
        int step = n-(n+1)/2+1;
        // cout<<end<<"\n";
        for(int i=n*k-step,dem=0;dem<k;i-=step) {ans+=a[i];dem++;}
        cout<<ans<<"\n";
    }
}