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
typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

int main(){
    CURTIME();
    INFILE("in.txt");
    OUFILE("out.txt");
    int n; cin>>n;
    int a[2*n],b[2*n+1];
    For(i,0,n) cin>>a[i];
    map<int, int> mm;
    For(i,0,n) {cin>>b[i]; mm[b[i]]=i;}
    
    int check[n+1];
    For(i,0,n) {
        check[i] = mm[a[i]]-i;
    }
    // For(i,0,n) {
    //      cout<<check[i]<<" ";
    // }
    // cout<<"\n";
    map<int, int> m;
    int res=0;
    For(i,0,n){
        m[check[i]]++;
        m[check[i]-n]++;
        res=max(res,m[check[i]]);
    }
    cout<<res;
}