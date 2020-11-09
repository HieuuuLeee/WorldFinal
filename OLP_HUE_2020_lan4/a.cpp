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

map<pair<int,int>, int> check;
int main(){
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    vector<pair<int,int>> a;
    pair<int,int> dis[9] = {{1,2},{2,1},{-1,-2},{-1,2},{-2,1},{-2,-1},{1,-2},{2,-1}};
    pair<int,int> diss[9] = {{0,1},{1,0},{0,-1},{0,1},{-1,0},{-1,0},{0,-1},{1,0}};
    pair<int,int> disss[9] = {{0,2},{2,0},{0,-2},{0,2},{-2,0},{-2,0},{0,-2},{2,0}};
    char c;
    For(i,1,5){
    	For(j,1,5){
    		cin>>c;
    		if(c=='k'){
    			check[mp(i,j)]=1;
    			a.pb({i,j});
    		}
    	}
    }
    for(auto i:a){
    	For(j,0,7){
    		// cout<<i.fi+dis[j].fi<<" "<<i.se+dis[j].se<<"\n";
    		if(check[{i.fi+dis[j].fi, i.se+dis[j].se}]==1 || check[{i.fi+diss[j].fi, i.se+diss[j].se}]==1){
    			cout<<"invalid";
    			return 0;
    		} //&& check[{i.fi+diss[j].fi, i.se+diss[j].se}]==0 && check[{i.fi+disss[j].fi, i.se+disss[j].se}]==0
    		check[{i.fi+dis[j].fi, i.se+dis[j].se}];
    	}
    }
    cout<<"valid";
    return 0;
}