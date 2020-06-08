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
#define Forl(i,a,b) for (ll i=a;i<b;i++)
#define Fodl(i,b,a) for (ll i=b;i>a;i--)
#define ForV(v) for (auto it = v.begin(); it!=v.end(); ++it)
typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)
 
int a[60][60];
 
int conv(char tmp){
    if(tmp=='.') return 0;
    if(tmp=='#') return 1;
    if(tmp=='G') return 2;
    if(tmp=='B') return -1;
}
 
void dfs(int n, int m){
    queue<pair<int, int>> q;
    map<pair<int,int>, int> visited;
    q.pp(mp(n-1,m-1));
    while(!q.et()){
        pair<int, int> curr = q.front();
        // cout<<"**"<<curr.fi<<" "<<curr.se<<"\n";
        visited[curr] = 1;
        int i = curr.fi, j=curr.se;
        a[i][j] = 0;
        if(i-1>=0 && i-1<n && (a[i-1][j]==2||a[i-1][j]==0) && visited[mp(i-1,j)]==0){
            q.pp(mp(i-1,j));
        }
        if(i+1>=0 && i+1<n && (a[i+1][j]==2||a[i+1][j]==0) && visited[mp(i+1,j)]==0){
            q.pp(mp(i+1,j));
        }
        if(j-1>=0 && j-1<m && (a[i][j-1]==2||a[i][j-1]==0) && visited[mp(i,j-1)]==0){
            q.pp(mp(i,j-1));
        }
        if(j+1>=0 && j+1<m && (a[i][j+1]==2||a[i][j+1]==0) && visited[mp(i,j+1)]==0){
            q.pp(mp(i,j+1));
        }
        q.pop();
    }
}
 
int main(){
    CURTIME();
    INFILE("in.txt");
    OUFILE("out.txt");
    int t; cin>>t;
    while(t--){
        // cout<<"*"<<t<<"\n";
        int n,m,BB=0,GG=0; cin>>n>>m;
        
        For(i,0,n)
            For(j,0,m){
                char tmp; cin>>tmp;
                a[i][j] = conv(tmp);
                if(a[i][j]==-1) BB++;
                if(a[i][j]==2) GG++;
            }
        // For(i,0,n){
        //     For(j,0,m){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        int ch=1;
        if(a[n-1][m-1]==-1) {ch=0;}
        if(BB==0) {ch=1;}
        if(a[n-1][m-1]==-1) {ch=0;}
        For(i,0,n)
            For(j,0,m){
                if(a[i][j]==-1 &&(a[i+1][j]==2||a[i-1][j]==2||a[i][j+1]==2||a[i][j-1]==2))
                    {ch=0; i=n; j=m;}
                else if(a[i][j]==-1){
                    if(i+1<n&&a[i+1][j]!=-1) a[i+1][j]=1;
                    if(j+1<m&&a[i][j+1]!=-1) a[i][j+1]=1;
                    if(j-1>=0&&a[i][j-1]!=-1) a[i][j-1]=1;
                    if(i-1>=0&&a[i-1][j]!=-1) a[i-1][j]=1;
                }  
                // else if(a[i][j]==1 && (a[i+1][j]!=-1&&a[i-1][j]!=-1&&a[i][j+1]!=-1&&a[i][j-1]!=-1))
                //     a[i][j]=0;
            }
        // For(i,0,n){
        //     For(j,0,m){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        if(a[n-1][m-1]==1 && GG>=1) {ch=0;}
        if(a[n-1][m-1]==1 && GG==0) {ch=1;}
        dfs(n,m);
        For(i,0,n)
            For(j,0,m){
                if(a[i][j]==2) ch=0;
            }   
        if(ch==1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}