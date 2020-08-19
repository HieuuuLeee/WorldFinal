#include<bits/stdc++.h>
using namespace std;

int nxt[1000000],ans[1000000];

int getNext(int i){
	if(nxt[i]==0) return i;
	return nxt[i]=getNext(nxt[i]);
}

int main(){
	// freopen("../in.txt","r",stdin);

	int n,m;
	cin>>n>>m;
	// cout<<n<<" "<<m<<"\n";

	while(m--){
		int l,r,x;
		cin>>l>>r>>x;
		int cur=getNext(l);
		while(cur<=r){
			if(cur==x) cur++;
			else{
				ans[cur]=x;
				nxt[cur]=cur+1;
			}
			cur=getNext(cur);
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}