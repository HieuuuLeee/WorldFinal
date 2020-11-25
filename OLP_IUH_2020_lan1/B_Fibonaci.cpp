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

const ll MOD = 998244353;
const ll MAX = 1000005;

vector<vector<ll>> res = {{0,1},{1,1}}, ma = {{0,1},{1,1}};

void mul(vector<vector<ll>> &a,vector<vector<ll>> b){
	ll ra=2,ca=2,rb=2,cb=2;
	vector<vector<ll>> ress = {{0,0},{0,0}};
	For(i,0,ra-1)
		For(j,0,ca-1){
			For(ia,0,ca-1)
				ress[i][j] += (a[i][ia]*b[ia][j]) % MOD;
		}
	a = ress;
}

pair<ll,ll> solve(ll n){
	while(n>0){
		if(n&1){
			mul(res,ma);
		}
		mul(ma,ma);
		n>>=1;
	}
	return {res[0][0],res[0][1]};
}

int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    ll n; cin>>n;
    pair<ll,ll> ans = solve(n+1);
    cout<<(ans.fi*ans.se)%MOD;
}