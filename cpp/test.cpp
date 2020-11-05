#include <bits/stdc++.h>
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
ll res=0;
void simpleSieve(ll limit, vector<ll>& prime)
{
    bool mark[limit + 1];
    memset(mark, false, sizeof(mark));
 
    for (ll i = 2; i <= limit; ++i) 
    {
        if (mark[i] == false) 
        {
            prime.push_back(i);
            for (ll j = i; j <= limit; j += i)
                mark[j] = true;
        }
    }
}
void primesInRange(ll low, ll high)
{
    ll limit = floor(sqrt(high)) + 1;
    vector<ll> prime;
    simpleSieve(limit, prime);
    ll n = high - low + 1;
 
    bool mark[n + 1];
    memset(mark, false, sizeof(mark));
 
    for (ll i = 0; i < prime.size(); i++) 
    {
         
        ll loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low)
            loLim += prime[i];
        if(loLim==prime[i])
            loLim += prime[i];
         
        for (ll j = loLim; j <= high; j += prime[i])
            if(j != prime[i])
              mark[j - low] = true;
    }
 
    for (ll i = low; i <= high-2; i++)
        if (!mark[i - low] && !mark[i+2 - low]){
            cout<<i<<"\n";
            res++;
        }
    cout<<res;
}
int main()
{
    ll low, high;
    // INFILE("in.txt");
    // OUFILE("out.txt");
    cin>>low>>high;
    primesInRange(low, high);
    return 0;
}