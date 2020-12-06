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

map<int,int> checkC,checkP;
map<int,vector<int>> child,parent;
int cntC,cntP;
vector<tuple<int,int,int>> res;

int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int n;
    cin>>n; cntC=n;
    For(i,1,n){
    	int m;
    	cin>>m;
    	For(j,0,m-1){
    		int x;
    		cin>>x;
    		if(!checkP[x]){cntP++; checkP[x]=1;}
    		child[x].pb(i);
    		parent[i].pb(x);
    	}
    }
    vector<int> qu;
    qu.pb(1);
    // cout<<cntC<<" "<<cntP<<"\n";
    while(qu.size()!=0){
    	int i = qu[qu.size()-1];
    	qu.pop_back();
    	if(!checkC[i]) --cntC;
    	checkC[i] = 1;
    	if(parent[i].size()==1 && child[parent[i][0]].size()==1){
    		cout<<"impossible";
    		return 0;
    	}
    	for(auto j:parent[i]){
    		if(!checkP[j]) continue;
    		else{
    			for(auto k:child[j]){
    				if(!checkC[k] && k!=i){
    					qu.pb(k);
    					res.pb({i,k,j});
    					checkC[k]=1;
    					--cntC;
    				}
    			}
    			checkP[j]=0;
    			--cntP;
    		}
    	}
    }
    if(cntC==0){
    	for(auto ii:res){
    		int ll,cc,rr;
    		tie(ll,cc,rr) = ii;
    		cout<<ll<<" "<<cc<<" "<<rr<<"\n";
    	}
    }
    else cout<<"impossible";
}