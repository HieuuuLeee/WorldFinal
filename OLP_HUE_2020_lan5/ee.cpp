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


int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");

    int n,k; cin>>n>>k;
    if(k>n) {cout<<0; return 0;}
    vector<long long> a(n);
    long long s=0;

    for(long long &i:a) cin>>i;
    for(auto i:a) s+=i;
    sort(all(a));
    long long ans = 1;
    while(s/ans!=k){
        long long tmp = s/k;
        for(int i=n-1;a[i]>tmp;i--){
            s-=a[i]-tmp;
            a[i]=tmp;
        }
        ans = tmp;
        // cout<<s<<"\n";
    }
    cout<<ans;
}