#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pp push
#define et empty
#define mp make_pair

#ifdef ONLINE_JUDGE
#define CURTIME()         ;
#define INFILE(name)      ;
#define OUFILE(name)      ;
#define DEBUG             ;
#define DUMP(value)       ;
#else
#define CURTIME()         cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define DEBUG             cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
#define DUMP(value)       cerr << "[" << (#value) << "]: " << (value) << el
#endif
#define For(i,a,b) for (int i=a;i<b;i++)
#define Fod(i,b,a) for (int i=b;i>a;i--)
typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

int bfs(ll a,ll b,ll k){
	map<pair<ll, ll>, int> visit;
	queue<tuple<ll, ll, int>> q;
	q.push({0, 0, 0});
	while(!q.et()){
		tuple<ll, ll, int> curr = q.front();
		ll m = get<0>(curr), n = get<1>(curr), res = get<2>(curr);
		if(m + n == k) return res;

		if(m>0 && !visit[mp(0,n)]){
			q.push({0,n,res+1});
			visit[mp(0,n)]=1;
		}
		if(n>0 && !visit[mp(m,0)]){
			q.push({m,0,res+1});
			visit[mp(m,0)]=1;	
		}
		//=================
		if(m<a && !visit[mp(a,n)]){
			q.push({a,n,res+1});
			visit[mp(a,n)]=1;
		}
		if(n<b && !visit[mp(m,b)]){
			q.push({m,b,res+1});
			visit[mp(m,b)]=1;	
		}
		//==================
		if(m<a && n>0 && n+m<=a && !visit[mp(m+n,0)]){
			q.push({m+n,0,res+1});
			visit[mp(m+n,0)]=1;
		}
		if(m<a && n>0 && n+m>a && !visit[mp(a,n-(a-m))]){
			q.push({a,n-(a-m),res+1});
			visit[mp(a,n-(a-m))]=1;
		}
		//==================
		if(n<b && m>0 && n+m<=b && !visit[mp(0,m+n)]){
			q.push({0,m+n,res+1});
			visit[mp(0,m+n)]=1;
		}
		if(n<b && m>0 && n+m>b && !visit[mp(m-(b-n),b)]){
			q.push({m-(b-n),b,res+1});
			visit[mp(m-(b-n),b)]=1;
		}
		q.pop();
	}
	return -1;
}

int main(){
	CURTIME();
    INFILE("../in.txt");
    OUFILE("../out.txt");
    // ll a=3,b=5,k=4; 
    ll a,b,k; 
    cin>>a>>b>>k;
    // cout<<a<<" "<<b<<" "<<k<<"\n";
    cout<<bfs(a, b, k);
}