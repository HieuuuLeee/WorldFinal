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
 
// long long ans;
vector<vector<int>> ansvt;
int solve(string a[],int i,int j){
    int cnt = 0;
    vector<pair<int,int>> p1,p0;
    // cout<<i<<" "<<j<<"*\n";
    For(ii,i,i+1){
        For(jj,j,j+1){
            if(a[ii][jj]=='1'){
                cnt++;
                p1.pb({ii,jj});
                // cout<<ii<<" "<<jj<<"**\n";
            }
            else p0.pb({ii,jj});
            a[i][j]='0';
        }
    } 
    // cout<<"cnt: "<<cnt<<"\n";
    if(cnt==0) return 0;
    if(cnt==1){
        vector<int> v;
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p0[0].fi); v.pb(p0[0].se); v.pb(p0[1].fi); v.pb(p0[1].se);
        ansvt.pb(v);
        v.clear();
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p0[0].fi); v.pb(p0[0].se); v.pb(p0[2].fi); v.pb(p0[2].se);
        ansvt.pb(v);
        v.clear();
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p0[1].fi); v.pb(p0[1].se); v.pb(p0[2].fi); v.pb(p0[2].se);
        ansvt.pb(v);
        return 3;
    }
    if(cnt==2){
        vector<int> v;
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p0[0].fi); v.pb(p0[0].se); v.pb(p0[1].fi); v.pb(p0[1].se);
        ansvt.pb(v);
        v.clear(); //cout<<"size:"<<v.size()<<"\n";
        v.pb(p1[1].fi); v.pb(p1[1].se); v.pb(p0[0].fi); v.pb(p0[0].se); v.pb(p0[1].fi); v.pb(p0[1].se);
        ansvt.pb(v);
        return 2;
    }
    if(cnt==3){
        vector<int> v;
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p1[1].fi); v.pb(p1[1].se); v.pb(p1[2].fi); v.pb(p1[2].se);
        ansvt.pb(v);
        return 1;
    }
    if(cnt==4){
        vector<int> v;
        v.pb(p1[1].fi); v.pb(p1[1].se);v.pb(p1[2].fi); v.pb(p1[2].se); v.pb(p1[3].fi); v.pb(p1[3].se); 
        ansvt.pb(v);
        v.clear();
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p1[1].fi); v.pb(p1[1].se); v.pb(p1[2].fi); v.pb(p1[2].se);
        ansvt.pb(v);
        v.clear();
        v.pb(p1[0].fi); v.pb(p1[0].se);v.pb(p1[1].fi); v.pb(p1[1].se);v.pb(p1[3].fi); v.pb(p1[3].se);
        ansvt.pb(v);
        v.clear();
        v.pb(p1[0].fi); v.pb(p1[0].se); v.pb(p1[2].fi); v.pb(p1[2].se); v.pb(p1[3].fi); v.pb(p1[3].se);
        ansvt.pb(v);
        return 4;
    }
}
int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int t;
    cin>>t; //cout<<t;
    while(t--){
        ansvt.clear();
        int n,m; 
        int ans=0;
        cin>>n>>m; //cout<<"nm:"<<n<<" "<<m<<"\n";
        string a[n+1];
        For(i,0,n-1) cin>>a[i];
        for(int i=0;i<(n/2*2-1);i+=2){
            for(int j=0;j<(m/2*2-1);j+=2){
                ans += solve(a,i,j);
                a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]='0';
            }
            if(m%2==1) {ans+=solve(a,i,m-2);a[i][m-2]=a[i+1][m-2]=a[i][m-2+1]=a[i+1][m-2+1]='0';}
        }
        if(n%2==1){
            for(int j=0;j<(m/2*2-1);j+=2){
                ans += solve(a,n-2,j); 
                a[n-2][j]=a[n-2+1][j]=a[n-2][j+1]=a[n-2+1][j+1]='0';
            }
            if(m%2==1) {ans+=solve(a,n-2,m-2);a[n-2][m-2]=a[n-2+1][m-2]=a[n-2][m-2+1]=a[n-2+1][m-2+1]='0';}
        }
        cout<<ans<<"\n";
        for(auto i:ansvt){
            for(auto j:i) cout<<j+1<<" ";
            brln;
        }
 
        // For(i,0,n-1) cout<<a[i]<<"\n";
    }
}