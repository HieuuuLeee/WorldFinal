// https://codeforces.com/contest/1452/problem/B
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

long long ans[1000005];
int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    int t;
    cin>>t; //cout<<t;
    while(t--){
        int n; cin>>n;
        ll sum = 0,tmp,mx=0;
        For(i,1,n) {
            cin>>tmp;
            mx = max(tmp,mx);
            sum+=tmp;
        }
        ll summ = sum;
        while(sum%(n-1) || sum/(n-1)!=mx){
            if(mx <= sum/(n-1)) mx = (sum+n-2)/(n-1);
            else sum = mx*(n-1);
        }
        cout<<sum - summ<<"\n";
    }
}