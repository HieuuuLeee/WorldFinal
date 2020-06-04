#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
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
typedef int64_t ll;
typedef uint64_t ull;
#define brln cout << "\n";
#define el                  "\n"
#define all(v)              (v).begin(), (v).end()
#define rall(v)             (v).rbegin(), (v).rend()
#define bit(x, i)           (((x) >> (i)) & 1)
#define bitcount(n)         __builtin_popcountll(n)

const int M = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  CURTIME();
  INFILE("../in.txt");
  OUFILE("../out.txt");
  int n, m;
  cin >> n >> m;
  vector<int> par(n), rnk(n, 0);
  iota(begin(par), end(par), 0);
  vector<pair<int, int>> thread(m);
  for (auto& [i, j] : thread) cin >> i >> j, --i, --j;
  int Q;
  cin >> Q;
  vector<int> q(Q);
  bitset<M> has;
  for (int& i : q) {
    cin >> i; --i;
    has[i] = true;
  }
  function<int(int)> root = [&](int v) {
    return v == par[v] ? v : par[v] = root(par[v]);
  };
  auto uniset = [&](int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b)
      return;
    if (rnk[a] < rnk[b])
      swap(a, b);
    par[b] = a;
    rnk[a] += rnk[a] == rnk[b];
  };
  for (int i = 0; i < m; i++) {
    if (!has[i]) {
      uniset(thread[i].first, thread[i].second);
    }
  }
  bitset<M> cc;
  for (int i = 0; i < n; i++) {
    cc[root(i)] = true;
  }
  int ncc = cc.count();
  int minus = 0;
  list<int> ans;
  reverse(begin(q), end(q));
  for (int i : q) {
    ans.push_front(ncc);
    if (root(thread[i].first) != root(thread[i].second))
      ncc -= 1;
    uniset(thread[i].first, thread[i].second);
  }
  for (int i : ans)
    cout << i << ' ';
  return 0;
}