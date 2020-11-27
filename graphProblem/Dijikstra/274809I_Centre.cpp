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
const int MAX = 1000005;
 
map<int,int> check;
vector<vector<pair<int,int>>> nxt(MAX);
map<int,int> parent;
map<int,int> visited;
int n,m; 
 
void djik(int u,int v, bool direct){
	priority_queue<tuple<int,int,int>> q;
	q.push({0,u,0});
	while(!q.et()){
		int W,U,P;
		tie(W,U,P) = q.top(); q.pop();
		U = abs(U);
		P = abs(P);
		if(visited[U]) continue;
		visited[U]=1;
		cout<<U<<" "<<W<<" "<<P<<"*\n";
		if(!parent[U]) parent[U]=P;
		if(U==v) return;
		if(!direct) reverse(all(nxt[U]));
		for(auto i:nxt[U]){
			// cout<<(direct?1:(-1))<<"\n";
			if(!visited[i.fi]) q.push({W-i.se,(i.fi)*(direct?1:(-1)),U*(direct?1:(-1))});
		}
	}
	cout<<"BUG!!\n";
	return;
}
 
void backTrack(int u,int v){
	int i = 1;
	while(u!=v){
		// cout<<u<<"\n";
		check[u]++;
		u=parent[u];
	}
	check[v]++;
	return;
}
 
int main() {
    fast;
    // INFILE("../../in.txt");
    // OUFILE("../../out.txt");
    cin>>n>>m;
    For(i,1,m){
    	int u,v,w; cin>>u>>v>>w;
    	nxt[u].pb({v,w});
    	nxt[v].pb({u,w});
    }
    djik(1,n,1);
    backTrack(n,1);
    parent.clear();
    visited.clear();
    djik(n,1,0);
    // cout<<"hh";
    backTrack(1,n);
    vector<int> ans;
    For(i,1,n) if(check[i]!=2) ans.pb(i);
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i<<"\n";
    return 0;
}