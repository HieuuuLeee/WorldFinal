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

long long ans;
pair<int,int> dir8[9] = {{0,1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1},{0,-1}};
pair<int,int> dir4[5] = {{0,1},{0,-1},{1,0},{-1,0}};
string s[MAX];

bool check(int i,int j,int r,int c){
    return (i>=0 && j>=0 && i<r && j<c);
}

int bfs(int r,int c){
    int ans=-1;
    priority_queue<tuple<int,int,int>> qu;
    For(i,0,r-2) if(check(i,0,r,c) && s[i][0]!='@') {
        qu.push({-(s[i][0]=='.'),i,0}); s[i][0]='@';
    }
    For(i,0,c-1) if(check(r-1,i,r,c) && s[r-1][i]!='@') {
        qu.push({-(s[r-1][i]=='.'),r-1,i}); s[r-1][i]='@';
    }
    while(!qu.et()){
        int R,C,K;
        tie(K,R,C)=qu.top();
        if(R==0||C==c-1){ans = -K; return ans;}
        qu.pop();
        For(i,0,7){
            int RR = R+dir8[i].fi, CC = C+dir8[i].se;
            if(check(RR,CC,r,c)){
                if(s[RR][CC]!='@') {
                    qu.push({K - (s[RR][CC]=='.'),RR,CC});
                    s[RR][CC]='@';
                }
            }
        }   
    }
    return ans;
}

int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    int r,c;
    while((cin>>r>>c),r||c){
        For(i,0,r-1){
            cin>>s[i]; 
        }
        cout<< bfs(r,c) <<"\n";
    }
}