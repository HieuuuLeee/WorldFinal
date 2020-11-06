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

int n,t,res,tmp;
map<int, int> check;
ll a[502][502];
int main(){
	fast;
	INFILE("../in.txt");
    OUFILE("../out.txt");
    cin>>n;
    For(i,1,n)
        For(j,1,n)
            if((i+j)%2){
                cin>>tmp; a[i][j]=tmp;
            }   
            else{
                cin>>tmp; a[i][j]=(-tmp);
            }
    For(i,1,n)
        For(j,1,n){
            if(i==1&&j==1) continue;
            if(i==1) a[i][j]=a[i][j-1]+a[i][j];
            else if(j==1) a[i][j]=a[i-1][j]+a[i][j];
            else a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    cin>>t;
    while(t--){
    	int x,y,xx,yy; cin>>x>>y>>xx>>yy;
        cout<<abs(a[xx][yy]-a[x-1][yy]-a[xx][y-1]+a[x-1][y-1])<<"\n";
    }
}