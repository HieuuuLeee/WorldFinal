#include<bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pp push
#define et empty
#define mp make_pair
#define pii pair<int,int>
 
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

string s;
int n,t;
pair<pii, int> st[inf*4];

pair<pii, int> build(pair<pii, int> st[],int n,int l,int r){
    if(l>r) return {{0,0},0};
    if(l==r){
        st[n].fi.fi = (s[l]=='(');
        st[n].fi.se = (s[l]==')');
        return st[n];
    }
    pair<pii, int> stl = build(st,n*2,l,(l+r)/2);
    pair<pii, int> str = build(st,n*2+1,(l+r)/2+1,r);
    int old = min(stl.fi.fi,str.fi.se);
    st[n].se = old + stl.se + str.se;
    st[n].fi.fi = stl.fi.fi + str.fi.fi - old;
    st[n].fi.se = stl.fi.se + str.fi.se - old;
    return st[n];
}
pair<pii, int> query(pair<pii, int> st[],int n,int l,int r,int ql,int qr){
    if(l>r) return {{0,0},0};
    if(l>qr||r<ql) return {{0,0},0};
    if(l>=ql && r<=qr) return st[n];
    pair<pii, int> stl = query(st,n*2,l,(l+r)/2,ql,qr);
    pair<pii, int> str = query(st,n*2+1,(l+r)/2+1,r,ql,qr);
    int old = min(stl.fi.fi,str.fi.se);
    int see = old + stl.se + str.se;
    int fifi = stl.fi.fi + str.fi.fi - old;
    int sese = stl.fi.se + str.fi.se - old;
    return {{fifi,sese},see};
}
int main(){
    fast;
    INFILE("in.txt");
    OUFILE("out.txt");
    cin>>s;
    n = s.size();
    build(st,1,0,n-1);
    cin>>t;
    while(t--){
        int x,y; cin>>x>>y;
        pair<pii, int> tmp = query(st,1,0,n-1,x-1,y-1);
        cout<<tmp.se*2<<"\n";
    }
}