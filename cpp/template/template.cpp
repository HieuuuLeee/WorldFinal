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

// sort(arr, arr+n, greater<int>()); 
int sum() { return 0; }

template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);  istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    // cout << "\n";
    cout << *it << " = " << a << endl;
    err(++it, args...);
    // cout << "\n";
}
inline ll read(){
    ll x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;
    ch=getchar();
}
while(ch>='0'&&ch<='9')     
    x=x*10+ch-'0',ch=getchar();
    return x*t;        
}
bool compare(pair<ll,ll> a, pair<ll,ll> b){
    return a.second - a.first < b.second - 
    b.first; 
}
pair<ll, ll> factor(ll n) {
    ll s = 0;
    while ((n & 1) == 0) {
        s++;
        n >>= 1;
    }
    return {s, n};
}
ll pow(ll a, ll d, ll n) {
    ll result = 1;
    a = a % n;
    while (d > 0) {
        if (d & 1) result = result * a % n;
        d >>= 1;
        a = a * a % n;
    }
    return result;
}
bool test_a(ll s, ll d, ll n, ll a) {
    if (n == a) return true;
    ll p = pow(a, d, n);
    if (p == 1) return true;
    for (; s > 0; s--) {
        if (p == n-1) return true;
        p = p * p % n;
    }
    return false;
}
bool miller(ll n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    ll s, d;
    tie(s, d) = factor(n-1);
    // return test_a(s, d, n, 2) &&  test_a(s, d, n, 3);
    return test_a(s, d, n, 2) && test_a(s, d, n, 7) && test_a(s, d, n, 61);
}
ll nCr(ll n, ll r){
  ll tmp = n-r;
  for(ll i = n-1; i > tmp; i--)
    n *= i;
  for(ll i = r-1; i > 1; i--)
    r *= i;
  return n/r;
}

ll NCR(int n, int r){
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;    k *= r;
            ll m = __gcd(p, k);
            p /= m;    k /= m;
            n--;       r--;
        }
    }
    else p = 1;
    return p;
}
 
inline ll mul(ll a, ll b, ll MOD = (1LL<<62)){
  return ((((a)%MOD)*((b)%MOD))%MOD);
}
 
inline ll add(ll a, ll b, ll MOD = (1LL<<62)){
  return ((((a)%MOD)+((b)%MOD))%MOD);
}
 
inline ll Pow(ll base, ll exp, ll MOD = (1LL<<62)){
  ll ans = 1;
  while(exp){
    if(exp & 1)
      ans = (ans*base)%MOD;
    exp >>= 1;
    base = (base*base)%MOD;
  }
  return ans;
}
void sieve(int N) {
    bool isPrime[1000000];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
}}}
//=====================================================
 // O((R−L+1)loglog(R)+(√R)loglog(√R)).
vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

///======================================
ll minPrime[1000000];
void pre_factorize(ll n){
  for (ll i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) { //if i is prime
        for (ll j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
  }}}}
  for (ll i = 2; i <= n; ++i) {
      if (minPrime[i] == 0) {
          minPrime[i] = i;
  }}
}
vector<ll> factorize(ll n) {
    vector<ll> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];}
    return res;}

vector<ll> factorize_hh(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;}}
    if (n != 1) {
        res.push_back(n);}
    return res;}


ll n;
int main(){
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    cout<<pow(2,5,10);
    // cout << nCr(100000000000000000,50);
    // cout << miller(23);
    // cout << factor(510).first << factor(510).second;
    // For(i, 1, 10) cout << i << " " << (i & 1) << "\n";
    // cout << (10<<1);
    // ll a = 100000;
    // DUMP(a);
    // pre_factorize(1000000);
    // vector<ll> x = factorize(a);
    // for(auto i : x) cout << i << " "; 
    // vector<ll> x = factorize_hh(a);
    // for(auto i : x) cout << i << " ";
    // CURTIME();
}
// xc = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / d;
// yc = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / d;