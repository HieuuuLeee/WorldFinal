#include<bits/stdc++.h>
using namespace std;

set<int> alive;
int ans[1000000];

int main(){
	freopen("../../in.txt","r",stdin);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) alive.insert(i);

	while(m--){
		int l,r,x;
		cin>>l>>r>>x;
		auto ll=alive.lower_bound(l);
		vector<int> erasene;
		while(*ll<=r){
			if(*ll!=x && *ll>=l && *ll<=r){
				ans[*ll]=x;
				erasene.push_back(*ll);
				// alive.erase(*ll);	
			}
			ll++;
		}
		// for(auto i:erasene) alive.erase(i);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}