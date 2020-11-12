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


int main() {
    fast;
    INFILE("in.txt");
    OUFILE("out.txt");
    float ans;
    int x,y,xx,yy,xxx,yyy;
    cin>>x>>y>>xx>>yy>>xxx>>yyy;
    int xmin = min(xx,xxx);
    int xmax = max(xx,xxx);
    int ymin = min(yy,yyy);
    int ymax = max(yy,yyy);
    if(x<xmin && y<ymin){
        ans = sqrt((xmin-x)*(xmin-x) + (y-ymin)*(y-ymin));
    }
    if(x>=xmin && x<=xmax && y<=ymin){
        ans = ymin-y;
    }
    if(x>xmax && y<=ymin){
        ans = sqrt((xmax-x)*(xmax-x) + (y-ymin)*(y-ymin));
    }
    if(x>xmax && y<=ymax && y>=ymin){
        ans = x-xmax;
    }
    if(x>xmax && y>ymax){
        ans = sqrt((xmax-x)*(xmax-x) + (y-ymax)*(y-ymax));
    }
    if(x<=xmax && x>=xmin && y>=ymax){
        ans = y-ymax;
    }
    if(x<xmin && y>=ymax){
        ans = sqrt((xmin-x)*(xmin-x) + (y-ymax)*(y-ymax));
    }
    if(x<xmin && y>ymin && y<ymax){
        ans = xmin-x;
    }
    printf("%.1f",ans);
}