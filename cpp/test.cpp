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
const int maxn=200007;

int n,k,ans=0;
int cnt[maxn][26];
string s;

int differ(int u,int v){
    int ret=0,mx=0;
    for (int j=0;j<26;++j){
        ret+=cnt[u][j]+cnt[v][j];
        mx=max(mx,cnt[u][j]+cnt[v][j]);
    }
    // cout<<"ret:"<<ret<<" "<<"mx:"<<mx<<"\n";
    return ret-mx;
}

int main(){
    CURTIME();
    INFILE("in.txt");
    OUFILE("out.txt");
    int t;
    cin>>t;
    while (t--){
        cin>>n>>k>>s;
        for (int i=0;i<k;++i){
            for (int j=0;j<26;++j){
                cnt[i][j]=0;
            }
        }
        for (int i=0;i<n;++i){
            // cout<<"*:"<<s[i]-'a'<<"\n";
            cnt[i%k][s[i]-'a']++;
        }
        // For(i,0,k){For(j,0,2) cout<<cnt[i][j]<<" "; cout<<"\n";}
        int ans=0;
        for (int i=0;i<k;++i){
            ans+=differ(i,k-1-i);
            // cout<<"ans:"<<ans<<"\n";
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}