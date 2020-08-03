// https://codeforces.com/contest/808/problem/G?f0a28=1
#include<bits/stdc++.h>
using namespace std;
int KMP(string t, string p){
	int res=0,n=t.size(),m=p.size();
	vector<int> pi(m, 0);
	for(int i=1,k=0; i<m; ++i){
		while(k && p[i]!=p[k]) k = pi[k-1];
		if(p[i]==p[k]) k++;
		pi[i] = k;
	}
	for(auto i:pi) cout << i <<" "; cout<<"\n";

 	for(int i=0,k=0; i<n; ++i){
		while(k && (t[i] != p[k] && t[i]!='?')) k = pi[k-1];
		if(t[i]==p[k] || t[i]=='?') ++k;
		if(k == m) ++res;
	}
	return res;
}
int main(){
	freopen("../in.txt", "r", stdin);
	string t,p;
	cin>>t>>p;
	cout << KMP(t,p);
}