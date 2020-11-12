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

struct Node{
    int lazy;
    int val,ind;
};

int a[MAX],n,r,m;
Node st[MAX*4][3];

void up(int node){
        st[node][1].val = st[node*2][1].val>=st[node*2+1][1].val?st[node*2][1].val:st[node*2+1][1].val;
        st[node][1].ind = st[node*2][1].val>=st[node*2+1][1].val?st[node*2][1].ind:st[node*2+1][1].ind;
        st[node][0].val = st[node*2][0].val<=st[node*2+1][0].val?st[node*2][0].val:st[node*2+1][0].val;
        st[node][0].ind = st[node*2][0].val<=st[node*2+1][0].val?st[node*2][0].ind:st[node*2+1][0].ind;   
        return;
}
void down(int node){
    int VAL = st[node][0].lazy;
    st[node*2][0].lazy = min(st[node*2][0].lazy+VAL,MAX);
    st[node*2+1][1].lazy = min(st[node*2+1][1].lazy+VAL,MAX);  
    st[node][1].lazy=st[node][0].lazy=0;
    if(VAL>=MAX){
        st[node*2][0].val=VAL; st[node*2][1].val=-VAL;
        st[node*2+1][0].val=VAL; st[node*2+1][1].val=-VAL;
    }
    else{
        st[node*2][0].val+=VAL; st[node*2][1].val+=VAL;
        st[node*2+1][0].val+=VAL; st[node*2+1][1].val+=VAL;
    } 
    return;
}
void build(int node, int l, int r){
    if(l>r) return;
    if(l==r){
        st[node][0].val = st[node][1].val = a[l];
        st[node][0].lazy = st[node][1].lazy = 0;
        st[node][0].ind = st[node][1].ind = l;
        return;
    }
    int mid = (l+r)>>1;
    build(node*2,l,mid); build(node*2+1,mid+1,r);
    up(node);
    return;
}

void update(int node, int l, int r, int ql ,int qr, int upval){
    if(l>r) return;
    if(l>qr || r<ql){
        // down(node,0);
        return;
    }
    if(l>=ql&&r<=qr){
        // down(node,upval);
        st[node][0].lazy = min(st[node][0].lazy+upval,MAX);
        st[node][1].lazy = min(st[node][1].lazy+upval,MAX);
        st[node][0].val=min(upval+st[node][0].val, MAX);
        if(upval==MAX) st[node][1].val=-upval; else st[node][1].val+=upval;
        // st[node][0].val+=upval;
        return;
    }
    down(node);
    int mid=(l+r)>>1;
    update(node*2,l,mid,ql,qr,upval); update(node*2+1,mid+1,r,ql,qr,upval);
    up(node);
    return;
}

int get(int node, int l, int r, int ql, int qr, bool ismax){
    if(l>r) return 0;
    if(l>qr || r<ql){
        // down(node,0);
        return 0;
    }
    if(l>=ql&&r<=qr){
        // down(node);
        return node;
    }
    down(node);
    int mid=(l+r)>>1;
    int L = get(node*2,l,mid,ql, qr, ismax);
    int R = get(node*2+1,mid+1,r,ql, qr, ismax);
    if(ismax) return (st[L][1].val>=st[R][1].val)?L:R;
    return st[L][0].val<=st[R][0].val?L:R;
}

int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");

    st[0][0].val=MAX;
    st[0][1].val=0;

    cin>>n>>r>>m;
    For(i,1,n) cin>>a[i];// prarr(a,n);
    // cout<<"asdf\n";
    build(1,1,n);
    int indx;
    // For(i,1,n*3) cout<<i<<": "<<st[i][0].val<<" "<<st[i][1].val<<"\n";
    For(i,1,m){
        indx = get(1,1,n,1,n,0);//cout<<st[indx][0].ind<<"\n";cout<<max(st[indx][0].ind-r,1)<<" "<<min(st[indx][0].ind+r,n)<<"\n";
        update(1,1,n,max(st[indx][0].ind-r,1),min(st[indx][0].ind+r,n),1);
        indx = get(1,1,n,1,n,1);//cout<<st[indx][1].ind<<"\n";cout<<max(st[indx][1].ind-r,1)<<" "<<min(st[indx][1].ind+r,n)<<"\n";
        update(1,1,n,max(st[indx][1].ind-r,1),min(st[indx][1].ind+r,n),MAX);
        For(i,1,n*3) cout<<i<<": "<<st[i][0].val<<" "<<st[i][1].val<<"\n";
    }
    // cout<<"---------------------\n";
    indx = get(1,1,n,1,n,1);
    if(st[indx][1].val<0) cout<<"0\n";
    else cout<<st[indx][1].val;
}