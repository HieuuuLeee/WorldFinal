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
vector<int> snt;
long long ans;

int solve (int n, int r) {
vector<int> p;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            p.push_back (i);
            snt.pb(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);
    int sum = 0;
    for (int msk=1; msk<(1<<p.size()); ++msk) {
        int mult = 1,
        bits = 0;
        for (int i=0; i<(int)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }
 
        int cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }
 
    return r - sum;
}

bool check(int n){
    for(auto i:snt)
        if(n%i==0) return false;
    return true;
}
int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    // cout<<solve(5,5)<<"\n";
    // cout<<solve(5,0)<<"\n";
    if(b-a<d-c){
        For(i,a,b)
            ans+=(long long)(solve(i,d)-solve(i,c-1));
    }
    else{
        For(i,c,d)
            ans+=(long long)(solve(i,b)-solve(i,a-1));   
    }
    cout<<ans;
}