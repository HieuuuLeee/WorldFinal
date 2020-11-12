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

typedef int64_t LL;
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

const LL MOD = 998244353;
const int MAX = 1000005;
int n,m,ans=0,cntdot; 
char a[1005][1005];
pair<int,int> direct[5] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};

bool check(int i, int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void bfs(int i,int j){
    queue<pair<int,int>> qu;
    qu.push({i,j});
    while(!qu.et()){
        // --cntdot;
        pair<int,int> cur = qu.front();
        i = cur.fi, j = cur.se;
        if(a[i][j]=='.')
            For(iii,1,4){
                int ii = i+direct[iii].fi, jj = j+direct[iii].se;
                if(check(ii,jj) && a[ii][jj]=='.')
                    qu.push({ii,jj});
            }
        a[i][j] = '#';
        qu.pop();
    }
}

int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    cin>>n>>m;
    For(i,1,n)
        For(j,1,m)
            cin>>a[i][j];
    For(i,1,n)
        For(j,1,m)
            if(a[i][j]=='.') {++ans; bfs(i,j);}
    cout<<ans;
}