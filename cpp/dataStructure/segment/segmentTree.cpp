#include<bits/stdc++.h>
using namespace std;

vector<int> st(100000),a(100000);

int build(int node, int l, int r){
	if(l>r) return 0;
	if(l==r) st[node] = a[l];
	else{
		int ll = build(node*2+1, l, (l+r)/2);
		int rr = build(node*2+2, (l+r)/2+1, r);
		st[node] = ll+rr;
	}
	return st[node];
}

int update(int node, int l, int r, int ind, int val){
	if(l>ind || r<ind) return st[node];
	if(l==ind && r==ind) st[node] = val;
	else{
		int ll = update(node*2+1, l, (l+r)/2, ind, val);
		int rr = update(node*2+2, (l+r)/2+1, r, ind, val);
		st[node] = ll + rr;
	}
	return st[node];
}

int query(int node, int l, int r, int ql, int qr){
	if(ql>r || qr<l) return 0;
	if(l>=ql && r<=qr) return st[node];
	int ll = query(node*2+1, l, (l+r)/2, ql,qr);
	int rr = query(node*2+2, (l+r)/2 + 1, r, ql,qr);
	return ll + rr;
}

int main(){
	freopen("../in.txt", "r", stdin);
	int n,u,q;
	cin>>n>>u>>q;
	cout<<n<<" "<<u<<" "<<q<<"\n";
	for(int i=0;i<n;++i) cin>>a[i];
	build(0,0,n-1);
	for(int i=0;i<n*2;++i) cout<<st[i]<<" "; cout<<"\n";
	for(int i=0; i<u; ++i){
		int x,y;
		cin>>x>>y; cout<<x<<" "<<y<<"\n";
		update(0, 0, n-1, x-1, y);
	}
	for(int i=0;i<n*2;++i) cout<<st[i]<<" "; cout<<"\n";
	for(int i=0;i<q;++i){
		int x,y;
		cin>>x>>y;
		cout<<query(0,0,n-1,x-1,y-1)<<"\n";
	}
	// int x=3;
	// cout<<(3^2)<<"\n";
	// cout<<x;
}