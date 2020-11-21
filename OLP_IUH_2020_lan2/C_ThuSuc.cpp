// https://codeforces.com/contest/1452/problem/C
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

const ll MOD = 1000000007;
const int MAX = 500010;

struct Node{
    int lazy,val;
};

Node st[MAX*4];
int n,q,t,ql,qr,x,a[MAX],ans;

void UP(int node){
    st[node].val = max(st[node*2].val, st[node*2+1].val);
    return;
}

void DOWN(int node){
    int val = st[node].lazy;
    st[node*2].val = max(1, st[node*2].val+val);
    st[node*2].lazy+=val;
    st[node*2+1].val = max(1, st[node*2+1].val+val);
    st[node*2+1].lazy+=val;
    st[node].lazy=0;
    return;
}

void build(int node, int l, int r){
    if(l>r) return;
    if(l==r) {st[node].val = a[l]; return;}
    int mid = (l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    UP(node);
    return;
}

void update(int node, int l, int r,int ql,int qr){
    if(ql>r||qr<l || st[node].val == 1) return;
    if(l>=ql && r<=qr){
        st[node].val = max(1,st[node].val-1);
        st[node].lazy = st[node].lazy - 1;
        return;
    }
    DOWN(node);
    int mid = (l+r)>>1;
    update(node*2,l,mid,ql,qr);
    update(node*2+1,mid+1,r,ql,qr);
    UP(node);
    return;
}

void get(int node,int l,int r){
    if(l>r || x<1 || l>qr || r<ql || st[node].val==1) return;
    if(l==r){
        x/=st[node].val;
        if(x<1) ans=l;
        return;
    }
    DOWN(node);
    int mid = (l+r)>>1;
    get(node*2,l,mid);
    if(x>0) get(node*2+1,mid+1,r);
    return;
}

int main() {
    fast;
    // INFILE("../in.txt");
    // OUFILE("../out.txt");
    cin>>n>>q;
    For(i,1,n) cin>>a[i];
    build(1,1,n);
    while(q--){
        cin>>t;
        if(t==1){
            cin>>ql>>qr;
            update(1,1,n,ql,qr);
        }
        else{
            ans = 0;
            cin>>ql>>qr>>x;
            // cout<<x<<"*\n";
            get(1,1,n);
            cout<<((ans>0)?ans:-1)<<"\n";
        }
    }
}
