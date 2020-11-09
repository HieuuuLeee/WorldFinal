#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair

#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define Forl(i,a,b) for (ll i=a;i<=b;i++)
#define Fodl(i,b,a) for (ll i=b;i>=a;i--)

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

const int inf = 1e6+5;
int main(){
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int t; cin>>t;
    while(t--){
        int n,flag=1;cin>>n;
        string s[n+1];
        For(i,0,n-1) cin>>s[i];
        Fod(i,n-2,0){
            Fod(j,i,0)
                if(s[j][i]=='1'&&s[j][i+1]=='0'&&s[j+1][i]=='0'){prno;i=j=-1;}
            if(i==-1) {flag=0;break;}
            Fod(j,i,0)
                if(s[i][j]=='1'&&s[i][j+1]=='0'&&s[i+1][j]=='0'){prno;i=j=-1;}
            if(i==-1) flag=0;
        }
        if(flag==1) pryes;
    }
}