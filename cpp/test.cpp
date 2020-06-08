#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pp push
#define et empty
#define mp make_pair

#ifdef ONLINE_JUDGE
#define CURTIME()         ;
#define INFILE(name)      ;
#define OUFILE(name)      ;
#define DEBUG             ;
#define DUMP(value)       ;
#else
#define CURTIME()         cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define DEBUG             cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
#define DUMP(value)       cerr << "[" << (#value) << "]: " << (value) << el
#endif
#define For(i,a,b) for (int i=a;i<b;i++)
#define Fod(i,b,a) for (int i=b;i>a;i--)
#define Forl(i,a,b) for (ll i=a;i<b;i++)
#define Fodl(i,b,a) for (ll i=b;i>a;i--)
#define ForV(v) for (auto it = v.begin(); it!=v.end(); ++it)
typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

vector<int> up;
ll po(int k){
    ll res = 1;
    For(i,0,k) res*=2;
    return res;
}
int main(){
    CURTIME();
    INFILE("in.txt");
    OUFILE("out.txt");
    int n; cin>>n;
    ll a[n+1];
    For(i,0,n) cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    // For(i,0,n) cout<<a[i]<<" "; cout<<"\n";
    map<ll,int> check;
    int ind=0;
    
    while(a[0]){
        if(a[0]%2==0){
            up.pb(ind);
        }
        a[0]/=2;
        ind++;
    }
    ll res=0;
    For(i,0,ind) res+=po(i);
    check[a[0]]++;
    map<int, int> rm;
    ForV(up) rm[*it]=1;
    // ForV(up) if(rm[*it]==1) cout<<*it<<" "; cout<<"\n";
    For(i,1,n){
        if(check[a[i]]) continue;
        check[a[i]]=1;
        int ind=0;
        while(a[i]){
            if(a[i]%2==0 && rm[ind]==0){
                up.pb(ind);
                rm[ind]=1;
            }
            if(a[i]%2==1) rm[ind]=-1;
            a[i]/=2;
            ind++;
        }
    }
    ForV(up) if(rm[*it]==1){
        res-=po(*it);
    }
    cout<<res;
}