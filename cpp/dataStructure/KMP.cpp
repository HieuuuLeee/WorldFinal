#include<bits/stdc++.h>
using namespace std;

vector<int> KMP(string t, string p){
	vector<int> res;

	int n = p.size();
	vector<int> pi(n, 0);
	for(int i=1, k=0; i<n; ++i){
		while(k && p[i]!=p[k]) k = pi[k-1];
		if(p[i]==p[k]) k++;
		pi[i] = k;
	}

	int m = t.size();
	for (int i = 0, k = 0; i < m; ++i) {
	    while (k && p[k] != t[i]) k = pi[k-1];
	    if (p[k] == t[i]) ++k;
	    if (k == p.size()) res.push_back(i-k+1);
	}
	if(res.size())
		return res;
	return {-1};
}

int main(){
	freopen("../in.txt", "r", stdin);
	string t,p;
	cin >> t >> p;
	cout<<t<<"\n"<<p<<"\n";
	vector<int> res = KMP(t, p);
	for(auto i:res) cout<<i<<" ";
	return 0;
}