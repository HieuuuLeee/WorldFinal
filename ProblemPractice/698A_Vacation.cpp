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
int main(){
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int t; cin>>t;
    int a[t+1];
    int b[3][t+1];
    For(i,1,t) cin>>a[i];
    if(a[1]==3) b[1][1]=b[2][1]=0;
    if(a[1]==0) b[1][1]=b[2][1]=1;
    if(a[1]==1 || a[1]==2) {b[1][1]=(a[1]==1?0:1); b[2][1]=(a[1]==1?1:0);} 
    For(i,2,t){
        if(a[i]==0) b[1][i]=b[2][i]=min(b[1][i-1],b[2][i-1])+1;
        else if(a[i-1]==0 && a[i]!=0){
            if(a[i]==3)b[1][i]=b[2][i]=b[1][i-1];
            else{
                b[a[i]][i] = b[1][i-1];
                b[3-a[i]][i] = b[1][i-1]+1;
            }
        }
        else if(a[i]!=3&&a[i-1]!=3){
            b[a[i]][i]=min(b[a[i]][i-1]+1,b[3-a[i]][i-1]);
            b[3-a[i]][i]=1+min(b[a[i]][i-1],b[3-a[i]][i-1]);
        }//b[1][i]=b[2][i]=b[1][i-1]+(1-abs(a[i]-a[i-1]));
        else if(a[i]!=3&&a[i-1]==3){
            b[a[i]][i]=min(b[a[i]][i-1]+1,b[3-a[i]][i-1]);
            b[3-a[i]][i]=1+min(b[a[i]][i-1],b[3-a[i]][i-1]);
        }//b[1][i]=b[2][i]=min(b[3-a[i]][i-1], b[a[i]][i-1]+1);
        else if(a[i]==3&&a[i-1]!=3){
            b[1][i]=min(b[a[i-1]][i-1]+2-a[i-1], b[3-a[i-1]][i-1]);
            b[2][i]=min(b[a[i-1]][i-1]+a[i-1]-1, b[3-a[i-1]][i-1]);
        }
        else{
            b[1][i]=min(b[1][i-1]+1, b[2][i-1]);
            b[2][i]=min(b[1][i-1], b[2][i-1]+1);  
        }
    }
    // For(i,1,t) cout<<b[1][i]<<" "; cout<<"\n";
    // For(i,1,t) cout<<b[2][i]<<" "; cout<<"\n";
    cout<<min(b[1][t],b[2][t]);
}