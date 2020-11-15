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
int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    ll t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m; //cout<<n<<" "<<m<<"*\n";
        pair<ll,int> a[n+2];
        ll tmp;
        bool flag = false;
        For(i,1,n) {cin>>tmp; a[i] = {tmp,i};}
        sort(a+1,a+n+1);
        ll mm = (m+1)/2;
        
        // Fod(i,n,1){
        //     if(a[i].fi<=m&&a[i].fi>=mm) {cout<<1<<"\n"; cout<<a[i].se<<"\n"; flag = true;}
        //     if(a[i].fi>m) continue;
        //     if(a[i].fi<mm){
        //         ll cur = a[i].fi;
        //         int j = lower_bound(a.begin()+1,a.end(), m-a[i].fi) - a.begin() - 1;
        //         while(cur<mm){
                    
        //         }
        //     }
        // }
        int i=1,j=1;
        ll cur = a[1].fi;
        while(i<=j && j<=n){
            if(cur<mm) {++j;cur+=a[j].fi;}
            else if(cur>m) {cur-=a[i].fi;++i;}
            else{
                cout<<j-i+1<<"\n";
                For(ind,i,j) cout<<a[ind].se<<" ";
                cout<<"\n";
                flag = true;
                j=n+1;
            }
        }
        if(!flag) cout<<"-1\n";
    }
    return 0;
}