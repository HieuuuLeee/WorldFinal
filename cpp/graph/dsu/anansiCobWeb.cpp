#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair
#define count_array(a,b,n,indx) {int fiIndx=-1; for(int iiiii=0;iiiii<n;iiiii++) if(iiiii==n-1||(a[iiiii]!=a[iiiii+1])) {b[indx++]=iiiii-fiIndx; fiIndx=iiiii;}}
#define prefix_arr(a,b,n) {b[0]=a[0]; for(int iiiii=1;iiiii<n,iiiii++) b[iiiii]=b[iiiii-1]+a[iiiii];}
#define suffix_arr(a,b,n) {b[n-1]=a[n-1]; for(int iiiii=n-2;iiiii>=0,iiiii--) b[iiiii]=b[iiiii+1]+a[iiiii];}

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
#define ForV(v) for (auto it = v.begin(); it!=v.end(); ++it)

typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

void union_set(int u, int v){

}

void findConnectedComponent(){

}

void check_ConnComp(int u, int v, int res){

}

int main() {
  CURTIME();
  INFILE("../in.txt");
  OUFILE("../out.txt");
  int n, m, q, res;
  cin >> n >> m;
  pair<int, int> a[n+1];
  For(i,0,m) cin>>a[i].fi>>a[i].se;
  cin>>q;
  int b[q+1];
  map<int, int> check;
  For(i,0,q){
    cin>>b[i];
    check[b[i]] = 1;
  } 
  For(i,0,m){
    if(!check[i]){
      union_set(a[i].fi, a[i].se);
    }
  }
  res = findConnectedComponent();
  list<int> results; results.pf(res);
  Fod(i,q-1,0){
    check_ConnComp(a[b[i]].fi, a[b[i]].fi, res);
    results.pf(res);
  }
  ForV(v) cout << *it;
  return 0;
}