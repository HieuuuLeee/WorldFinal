// https://codeforces.com/group/FLVn1Sc504/contest/274809/problem/I?fbclid=IwAR2jn0-pp4dX7-nOGmY5Y-bjZB1Iwz_ZSuCxkXgSkNjKnd2RTSaXrP1wLyE
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
const int MAX = 100005;
// long long ans;
int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");

    int t; cin>>t;
    while(t--){
    	int n; cin>>n;
    	int ans=0;
    	if(n==1) cout<<"0\n";
    	else if(n==2) cout<<"1\n";
    	else if(n==3) cout<<"2\n";
    	else if(n%2==0) cout<<"2\n";
    	else cout<<"3\n"; 
    	// cout<<ans<<"\n";
    }
}