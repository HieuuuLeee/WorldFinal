#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair
#define count_array(a,b,n,indx) {int fiIndx=-1; for(int iiiii=0;iiiii<n;iiiii++) if(iiiii==n-1||(a[iiiii]!=a[iiiii+1])) {b[indx++]=iiiii-fiIndx; fiIndx=iiiii;}}
#define prefix_arr(a,b,n) {b[0]=a[0]; for(int iiiii=1;iiiii<n,iiiii++) b[iiiii]=b[iiiii-1]+a[iiiii];}
#define suffix_arr(a,b,n) {b[n-1]=a[n-1]; for(int iiiii=n-2;iiiii>=0,iiiii--) b[iiiii]=b[iiiii+1]+a[iiiii];}

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
#define Forl(i,a,b) for (ll i=a;i<b;i++)
#define Fodl(i,b,a) for (ll i=b;i>a;i--)
#define ForV(v) for (auto it = v.begin(); it!=v.end(); ++it)

typedef int64_t ll;
typedef uint64_t ull;
#define prno                             cout<<"NO\n"
#define pryes                            cout<<"YES\n"
#define pryon                            pryes; else prno;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

int n,m,a[111111],u,v,res,visit[111111];
vector<vector<int>> child;

void travel(int cur, int check){
    visit[cur]=1;
    if(child[cur].size()==1&&visit[child[cur][0]]) {res++; return;}
    if(!a[cur]) check=0;
    ForV(child[cur]) if(!visit[*it] && check+a[*it]<=m) travel(*it, check+a[*it]);
}

int main() {
    CURTIME();
    INFILE("in.txt");
    OUFILE("out.txt");
    // DEBUG;
    cin>>n>>m;
    child.resize(n+1);
    For(i,1,n+1) cin>>a[i];
    For(i,0,n-1){
        cin>>u>>v;
        // DEBUG;
        child[u].pb(v);
        child[v].pb(u);
        // DEBUG;
    }
    // DEBUG; 
    travel(1,a[1]);
    cout<<res;
}