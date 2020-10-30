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

int n,pre[inf],suf[inf],st[inf*4];
map<ll,int> cnt,cnts,cntst;
ll a[inf],res;

int build(int n,int l,int r){
    if(l>r) return 0;
    if(l==r) return st[n]=cntst[l];
    return st[n] = build(n*2,l,(l+r)/2) + build(n*2+1,(l+r)/2+1,r);
}
int update(int n,int l,int r,int ind){
    if(l>r) return 0;
    if(ind<l||ind>r) return st[n];
    if(l==r && l==ind) return --st[n];   
    return st[n] = (update(n*2,l,(l+r)/2,ind) + update(n*2+1,(l+r)/2+1,r,ind));
}
int query(int n,int l,int r,int ql,int qr){
    if(l>r) return 0;
    if(l>=ql && r<=qr) return st[n];
    if(l>qr||r<ql) return 0;
    return query(n*2,l,(l+r)/2,ql,qr) + query(n*2+1,(l+r)/2+1,r,ql,qr);
}

int main(){
    fast;
    // INFILE("in.txt");
    // OUFILE("out.txt");
    cin>>n;
    For(i,1,n) cin>>a[i];
    For(i,1,n){
      cnt[a[i]]++;
      pre[i]=cnt[a[i]];
    }
    Fod(i,n,1){
      cnts[a[i]]++;
      suf[i]=cnts[a[i]];
    }
    For(i,1,n) cntst[pre[i]]++;
    build(1,1,n);
    For(i,1,n){
        update(1,1,n,suf[i]);
        if(pre[i]>1)res+=query(1,1,n,1,pre[i]-1);
    }
    cout<<res;
}