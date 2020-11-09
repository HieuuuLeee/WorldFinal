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

const ll MOD = 998244353;

map<pair<int,int>, int> check;
int main(){
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    vector<pair<int,int>> a;
    pair<int,int> dis[9] = {{1,2},{2,1},{-1,-2},{-1,2},{-2,1},{-2,-1},{1,-2},{2,-1}};
    pair<int,int> diss[9] = {{0,1},{1,0},{0,-1},{0,1},{-1,0},{-1,0},{0,-1},{1,0}};
    pair<int,int> disss[9] = {{0,2},{2,0},{0,-2},{0,2},{-2,0},{-2,0},{0,-2},{2,0}};
    char c;
    int cc=0,ll=0;
    For(i,1,5){
    	For(j,1,5){
    		cin>>c;
    		if(c=='k'){
                if((i+j)%2){
                    if(ll!=0){
                        cout<<"invalid";
                        return 0;
                    }
                    else{
                        ++cc;
                    }
                }
                else{
                    if(cc!=0){
                        cout<<"invalid";
                        return 0;
                    }
                    else{
                        ++ll;
                    }
                }
    		}
    	}
    }
    cout<<"valid";
    return 0;
}