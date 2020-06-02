# WorldFinal
## Copyright belong to IUH.AydaaaaComeback&WorldFinal ACM/ICPC Team
## TEMPLATE:
#### \#include<bits/stdc++.h>
#### using namespace std;

#### \#ifdef ONLINE_JUDGE
##### > \#define CURTIME()         ;
##### > \#define INFILE(name)      ;
##### > \#define OUFILE(name)      ;
##### > \#define DEBUG             ;
##### > \#define DUMP(value)       ;
#### \#else
> ##### \#define CURTIME()         cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
> ##### \#define INFILE(name)      freopen(name, "r", stdin)
> ##### \#define OUFILE(name)      freopen(name, "w", stdin)
> ##### \#define DEBUG             cerr << "##########\nRunning on Line: " << __LINE__ << "\nIn Function: " <<   __FUNCTION__ << "\n##########\n"
> ##### \#define DUMP(value)       cerr << "[" << (#value) << "]: " << (value) << el
### \#endif
> ##### \#define For(i,a,b) for (int i=a;i<b;i++)
> ##### \#define Fod(i,b,a) for (int i=b;i>a;i--)
> ##### typedef int64_t ll;
> ##### typedef uint64_t ull;
> ##### \#define brln cout << "\n";
> ##### \#define el                  "\n"
> ##### \#define all(v)              (v).begin(), (v).end()
> ##### \#define rall(v)             (v).rbegin(), (v).rend()
> ##### \#define bit(x, i)           (((x) >> (i)) & 1)
> ##### \#define bitcount(n)         __builtin_popcountll(n)