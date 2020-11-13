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

ll NCR(int n, int r){
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;    k *= r;
            ll m = __gcd(p, k);
            p /= m;    k /= m;
            n--;       r--;
        }
    }
    else p = 1;
    return p;
}

long long ans;
int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");

    int t; cin>>t;
    int r,c;
    while(t--){
    	ans=1;
    	cin>>r>>c;
    	// cout<<r<<" "<<c<<"\n";
    	For(i,1,r){
    		For(j,1,c){
    			if(i==1 && j==1) ans*=18%MOD;
    			else if((j==1&&i>1) || (i==1&&j>1)) ans*=6;
    			else ans*=2;
    			ans%=MOD;
    		}
    	}
    	cout<<ans%MOD<<"\n";
    }
    // cout<<NCR(3,2);
}