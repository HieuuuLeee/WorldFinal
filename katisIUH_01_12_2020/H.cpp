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

const ll MOD = 252097800623;
const int MAX = 1000005;
const int pow_e = 5;

int ans=MAX;
vector<vector<pair<ll,int>>> move_(4);

ll p_pow[5050];

void init_pow(){
	p_pow[0]=1;
	For(i,1,5005) p_pow[i]=(p_pow[i-1]*pow_e) % MOD;
}

ll getHash(string s) {
    ll hash_value = 0;
    for (int i=s.length()-1;i>=0;i--) {
    	char c = s[i];
        hash_value = (hash_value + ((ll)(c - 'A') * p_pow[s.length()-i-1])%MOD) % MOD;
    }
    return hash_value;
}

int get(int l1,int l2,int len){
	int chan = max(l1,l2);
	int ll1=len-l1,ll2=len-l2;
	if(!l1) ll1=0;
	if(!l2) ll2=0;
	int metmoi = max(ll1,ll2);
	int daudau = l1+ll2;
	int chongmat = ll1+l2;
	return min(min(chan,metmoi),min(daudau,chongmat));
}

int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    string s,s1,s2;
    cin>>s>>s1>>s2;

    init_pow();

    string ss = string(s.length(),'D');
    // cout<<s.length()<<"\n";
    // cout<<ss.length()<<"\n";

    ll valCheck = getHash(ss); 
    ll val = getHash(s);
    move_[0].pb({val,0});

    val = getHash(s1);
    move_[1].pb({val,0});
    int len = s1.length();
    For(i,1,len-1){
    	val= ((((val - ((s1[i-1]-'A')*p_pow[len-1])%MOD + MOD) % MOD)*5)%MOD + (s1[(i+len-1)%len]-'A'))%MOD;
    	// cout<<val<<"\n";
    	move_[1].pb({val,i});
    }

    val = getHash(s2);
    move_[2].pb({val,0});
    For(i,1,len-1){
    	int len = s2.length();
    	val= (((val - (s2[i-1]-'A')*p_pow[len-1]%MOD + MOD) % MOD)*5%MOD + (s2[(i+len-1)%len]-'A'))%MOD;
    	// cout<<val<<"\n";
    	move_[2].pb({val,i});
    }
    For(i,0,len-1){
 		For(j,0,len-1){
			if((move_[0][0].fi + move_[1][i].fi + move_[2][j].fi)%MOD == valCheck){
				int lech1 = move_[1][i].se, lech2 = move_[2][j].se;
				// cout<<lech1<<" "<<lech2<<"\n";
    			ans = min(get(lech1,lech2,len), ans);
			}
    	}   	
    }
    // cout<<valCheck<<"\n";
    if(ans!=MAX) cout<<ans;
    else cout<<"-1";
}