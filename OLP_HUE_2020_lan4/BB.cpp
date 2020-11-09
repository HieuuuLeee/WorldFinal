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

int main(){
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int n,r,m; cin>>n>>r>>m;
    int a[n+2];
    For(i,1,n) cin>>a[i];
    For(i,1,m){
        int mn=1000002,ind;
        For(j,1,n)
            if(mn>a[j]){mn=a[j]; ind=j;}
        For(j,max(0,ind-r),min(n,ind+r)){
            a[j]++;
        }
        int mx=0;
        For(j,1,n)
            if(mx<a[j]){mx=a[j]; ind=j;}
        For(j,max(0,ind-r),min(n,ind+r)){
            a[j]=0;
        }
    }
    int mx=0,ind;
    For(j,1,n)
        if(mx<a[j]){mx=a[j]; ind=j;}
    cout<<mx;
}