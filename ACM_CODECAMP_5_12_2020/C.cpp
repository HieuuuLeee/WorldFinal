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

int n,m,x,y;
int a[MAX];
vector<pair<int,int>> q;
vector<int> res;
int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    cin>>n;
    For(i,1,n){
    	cin>>x>>y;
    	q.pb({x,y});
    }
    cin>>m;
    For(i,1,m) cin>>a[i];
    bool check=false;
    for(auto i:q){
    	int low = lower_bound(a+1,a+m+1,i.fi);
    	// int up_id = upper_bound(a+1,a+m+1,i.se);
    	int up = (upper_bound(a+1,a+m+1,i.se)-1);
    	if(up-low+1>2) {cout<<"impossible"; return 0;}
    	cout<<low<<" "<<up<<"\n";
    	// cout<<*lower_bound(a+1,a+m+1,i.fi)<<" "<<*upper_bound(a+1,a+m+1,i.se)<<" "<<"\n";
    	// if((low>i.se&&up<i.fi) || (low==up && !check)){cout<<"impossible"; return 0;}
    	if(check){
    		res.pb(up);	
    		if(up==i.se){check=true;}
    		else check = false;
    	}
    	else{
    		res.pb(low);
    		res.pb(up);
    		if(up==i.se){check=true;}
    		else check=false;	
    	}
    	// if(up==i.se){res.pb(up); check=true;}
    }
    cout<<res.size()<<"\n";
    for(auto i:res) cout<<i<<" "; brln;
}