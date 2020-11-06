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
#define prarr(a,n)          For(i,1,n)cout<<a[i]<<" "; brln;
#define prvt(a)				for(auto i:a) cout<<i<<" "; brln;
#define bitcount(n)         __builtin_popcountll(n)

#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define fast              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,t,res,tmp;
map<int, int> check;
ll a[502][502];
pair<char,int> sorted[500001];
vector<long long> primes;
vector<char> i2ac(int n){
	vector<char> ans;
	while(n>0){
		ans.pb(char(n%10+'0'));
		n/=10;
	}
	return (reverse(all(ans)),ans);
}
void sieve(vector<long long> &primes, int n){
    vector<bool> mark(n + 1, false);
    for (long long i = 2; i <= n; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= n; j += i)
                mark[j] = true;
        }
    }
}
int main(){
	fast;
	// INFILE("../in.txt");
 //    OUFILE("../out.txt");
    cin>>n>>t;
    sieve(primes, 1e7);
    vector<char> ans;
   	For(i,0,n-1){
   		vector<char> cur=i2ac(primes[i]);
   		for(auto j:cur) ans.pb(j);
   	}
   	// prvt(ans);
   	For(i,0,ans.size()-1){
   		sorted[i] = {ans[i],i};
   	}
   	// sort(sorted,sorted+ans.size());
   	stack<pair<char,int>> st;
   	vector<pair<char,int>> order;
   	int ind = 0;
   	char currr;
   	while(ind<ans.size()){
   		while((ind<ans.size()-1 && ans[ind]<ans[ind+1]) || ind==ans.size()-1){
   			currr = ans[ind];
	   		while(!st.et() && st.top().fi<currr){
	   			order.pb(st.top());
	   			st.pop();
	   		}
   			order.pb({ans[ind],ind});
   			ind++;
	   	}
	   	while(ans[ind]>=ans[ind+1] && ind<ans.size()-1){
	   		currr = ans[ind];
	   		while(!st.et() && st.top().fi<currr){
	   			order.pb(st.top());
	   			st.pop();
	   		}
	   		st.push({ans[ind],ind});
	   		ind++;
	   	}
	   	if(ind==ans.size()-1) {st.push({ans[ind],ind}); ++ind;}
   	}
   	while(!st.et()){
   		order.pb(st.top());
	   	st.pop();
   	}
   	// for(auto i:order) cout<<i.fi<<" "; brln;
   	// for(auto i:order) cout<<i.se<<" "; brln;

   	For(i,0,t-1){
   		check[order[i].se]=1;
   	}
   	For(i,0,ans.size()-1)
   		if(!check[i]) cout<<ans[i];
}



