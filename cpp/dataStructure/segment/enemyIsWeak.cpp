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
 
int n,st[inf*4],stp[inf*4];
ll a[inf];
ull res;
 
void compresss(ll a[],int n){
    ll b[inf];
    For(i,1,n) b[i]=a[i];
    sort(b,b+n);
    For(i,1,n) a[i]=upper_bound(b,b+n,a[i])-b;
}
int update(int st[],int n,int l,int r,int ind,int state){
    if(l>r) return 0;
    if(ind<l||ind>r) return st[n];
    if(l==r && l==ind) return st[n]+=state;
    return st[n] = update(st,n*2,l,(l+r)/2,ind,state) + update(st,n*2+1,(l+r)/2+1,r,ind,state);
}
ll query(int st[],int n,int l,int r,int ql,int qr){
    if(l>r) return 0;
    if(l>=ql && r<=qr) return st[n];
    if(l>qr||r<ql) return 0;
    return query(st,n*2,l,(l+r)/2,ql,qr) + query(st,n*2+1,(l+r)/2+1,r,ql,qr);
}
int main(){
    fast;
    // INFILE("in.txt");
    // OUFILE("out.txt");
    cin>>n;
    For(i,1,n) cin>>a[i];
    compresss(a,n);
    For(i,2,n) update(stp,1,1,n,a[i],1);
    For(i,2,n-1){
        update(stp,1,1,n,a[i],-1);
        update(st,1,1,n,a[i-1],1);
        res+=query(st,1,1,n,a[i]+1,n)*query(stp,1,1,n,1,a[i]-1);
    }
    cout<<res;
}