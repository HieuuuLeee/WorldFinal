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
int n;
int a[MAX];
int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    cin>>n;
    For(i,0,n-1) cin>>a[i];
    int l=n,r=0;
    For(i,0,n-2){
    	if(a[i+1]<a[i]){
    		l=i;
    		while(a[i]==a[l] && i>=0) i--;
    		l=i+1;
    		break;
    	}
    }
    Fod(i,n-1,1){
    	if(a[i-1]>a[i]){
    		r=i;
    		while(a[i]==a[r] && i<n) i++;
    		r=i-1;
    		break;
    	}
    }
   	vector<int> rev;
    Fod(i,r,l) rev.pb(a[i]);
    For(i,l,r) a[i]=rev[i-l];
    // For(i,0,n-1) cout<<a[i]<<" "; brln;
    // cout<<l<<" "<<r; brln;
   	For(i,0,n-2)
   		if(a[i]>a[i+1]){
   			cout<<"impossible";
   			return 0;
   		}
    if(l==n && r==0) cout<<"1 1";
    else cout<<l+1<<" "<<r+1;
}