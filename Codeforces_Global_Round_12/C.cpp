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
#define pii					pair<int,int>

#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define fast              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll MOD = 1000000007;
const int MAX = 400;

int n;

bool check(vector<vector<int>> a,tuple<pii,pii,pii> t){
	pii mo,ha,ba;
	tie(mo,ha,ba) = t;
	if(a[mo.fi][mo.se]==a[ha.fi][ha.se] && a[mo.fi][mo.se]==a[ba.fi][ba.se]) 
		return true;
	return false;
}

bool cmp(pii t, pii tt){
	return (t.fi<tt.fi || (t.fi==tt.fi && t.se<tt.se));
}

tuple<pii,pii,pii> __sort(pii t, pii tt, pii ttt){
	vector<pii> v;
	v.pb(t);
	v.pb(tt);
	v.pb(ttt);
	sort(all(v),&cmp);
	return {v[0],v[1],v[2]};
}

int di1x[4] = {1,0,-1,0};
int di1y[4] = {0,1,0,-1};
int di2x[4] = {2,0,-2,0};
int di2y[4] = {0,2,0,-2};
// int a[MAX][MAX];

int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int t; cin>>t;
    while(t--){
    	cin>>n;
    	vector<vector<int>> a(n+5);
    	For(i,1,n){
    		For(j,1,n){
    			char s;
    			cin>>s;
    			if(s=='O') a[i].pb(2);
    			if(s=='X') a[i].pb(-2);
    			if(s=='.') a[i].pb(1);
    		}
    	}
    	map<pair<int,int>,int> visit,cnt;
    	int count=0;
    	For(i,1,n){
    		For(j,1,n){
    			For(ind,0,1){
    				if(check(a,{{i,j},{i+di1x[ind],j+di1y[ind]},{i+di2x[ind],j+di2y[ind]}})){
    					count++;
    					cnt[{i,j}]++;
						cnt[{i+di1x[ind],j+di1y[ind]}]++;
						cnt[{i+di2x[ind],j+di2y[ind]}]++;				
    				}
    			}
    		}
    	}
    	priority_queue<pair<int,pii>> qu;
    	For(i,1,n){
    		For(j,1,n){
    			qu.push({cnt[{i,j}],{i,j}});
    		}
    	}
    	cout<<count<<"*\n";
    	while(count){
    		pair<int,pii> cur = qu.top();
    		qu.pop();
    		if(cnt[{cur.se.fi,cur.se.se}] != cur.fi){
    			cur.fi = cnt[{cur.se.fi,cur.se.se}];
    			qu.push(cur);
    			continue;
    		}
    		count-=cur.fi;
    		int i = cur.se.fi, j = cur.se.se;
    		For(ind,0,3){
				if(check(a,{{i,j},{i+di1x[ind],j+di1y[ind]},{i+di2x[ind],j+di2y[ind]}})){
					// count++;
					cnt[{i,j}]=0;
					cnt[{i+di1x[ind],j+di1y[ind]}]--;
					cnt[{i+di2x[ind],j+di2y[ind]}]--;				

					a[i][j] = -a[i][j];
					// a[i+di1x[ind]][j+di1y[ind]] = -a[i+di1x[ind]][j+di1y[ind]];
					// a[i+di2x[ind]][j+di2y[ind]] = -a[i+di2x[ind]][j+di2y[ind]];
				}
			}
			if(check(a,{{i-1,j},{i,j},{i+1,j}})){
				cnt[{i,j}]=0;					
				cnt[{i-1,j}]=0;
				cnt[{i+1,j}]=0;

				a[i][j] = -a[i][j];
			}
			if(check(a,{{i,j-1},{i,j},{i,j+1}})){
				cnt[{i,j}]=0;					
				cnt[{i,j-1}]--;
				cnt[{i,j+1}]--;

				a[i][j] = -a[i][j];
			}
    	}
    	For(i,1,n){
    		For(j,1,n){
    			if(a[i][j]==1) cout<<'.';
    			if(a[i][j]==2) cout<<'O';
    			if(a[i][j]==-2) cout<<'X';
    		}
    		brln;
    	}
    }
}