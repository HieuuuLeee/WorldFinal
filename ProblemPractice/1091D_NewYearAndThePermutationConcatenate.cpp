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

const ll MOD = 998244353;
ll permu[1000021],invpermu[1000021],ans;
// ll ifac[1000020];
void permutate(int n){
    permu[0]=1;
    Forl(i,1,1000020) permu[i]=(permu[i-1]*i)%MOD;
}
// int gcd_extend(int a, int b, int *x, int *y) {
//   if (b == 0) {
//     *x = 1;
//     *y = 0;
//     return a;
//   }
//   int x1, y1;
//   int gcd = gcd_extend(b, a%b,  &x1, &y1);
//   *x = y1;
//   *y = x1 - (a / b) * y1;
//   return gcd;
// }
// int modulo_inverse_euclidean(int n, int m) {
//   int x, y;
//   if (gcd_extend(n, m, &x, &y) != 1) return -1; // not exist
//   return (x % m  + m) % m; // vì x có thể âm 
// }
// ull mul_inv(ull a, ull b = MOD) {
//     ull t1 = a, t2 = b, t3;
//     ull v1 = 1, v2 = 0, v3;
//     while (t2 != 1) {
//         ull x = t1 / t2;
//         t3 = t1 - x * t2;
//         v3 = v1 - x * v2;
//         t1 = t2, t2 = t3;
//         v1 = v2, v2 = v3;
//     }
//     return (v2 + b) % b;
// }
int main(){
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int n; cin>>n;
    permutate(n);
    Forl(i,1,1000020) invpermu[i] = MOD-invpermu[MOD%permu[i]]*(MOD/permu[i])%MOD;
    // ifac[0] = 1;
    // for (int i=1; i<1000002; i++) ifac[i] = ifac[i-1]*invpermu[i]%MOD;
    // invpermu[1] = 1;
    // for(int i = 2; i < 1000005; ++i)
    //     invpermu[i] = MOD - (MOD/i)*invpermu[MOD%i]%MOD;
    ans=n*permu[n]%MOD;
    Forl(i,1,n-1) ans-=(permu[n]*invpermu[i]);
    cout<<ans%MOD;
    // cout<<invpermu[10];
    // cout<<ans;
    // cout<<permu[n];
}
