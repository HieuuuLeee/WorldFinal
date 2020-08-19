#include<bits/stdc++.h>
using namespace std;
#define fi first;
#define se second;

int st[10000000];
int a[131073];

int build(int node, int l, int r, int state){
	if(l>r) return 0;
	if(l==r){
		st[node]=a[l];
		return st[node];
	}
	else{
		int ll=build(node*2+1,l,(l+r)/2,1-state);
		int rr=build(node*2+2,(l+r)/2+1,r,1-state);
		if(!state){
			st[node]=ll ^ rr;
		}
		else
			st[node]=ll | rr;
	}
	return st[node];
}

int update(int node, int l, int r, int i, int val,int state){
	if(l>i||r<i) return st[node];
	if(l==r&&l==i) st[node] = val;
	else{
		int ll=update(node*2+1,l,(l+r)/2,i,val,1-state);
		int rr=update(node*2+2,(l+r)/2+1,r,i,val,1-state);
		if(!state){
			st[node]=ll^rr;
		}
		else
			st[node]=ll|rr;	
	}
	return st[node];
}
int main(){
	freopen("../../in.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int nn = pow(2,n);
	for(int i=0;i<nn;i++) cin>>a[i];
	build(0,0,nn-1,n%2);
	while(m--){
		int p,b;
		cin>>p>>b;
		cout<<update(0,0,nn-1,p-1,b,n%2)<<"\n";
	}
}