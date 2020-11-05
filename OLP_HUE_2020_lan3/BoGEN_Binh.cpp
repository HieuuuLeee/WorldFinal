#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define M 1005000
#define MOD 1000000007
#define ii pair<ll, ll>
#define iii pair<ll, ii>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

ll n,k,power[35],hash[33333][32];
string s;

ll getHash(int id,int i,int j) {
    if (i==0) return hash[id][j]%MOD;
    return (hash[id][j] - hash[id][i-1]*power[j-i+1] + 1LL*MOD*MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 
    
    cin>>n>>k;

    power[0]=1;
    for (int i=1;i<=31;i++) power[i]=power[i-1]*31%MOD;
    
    for (int i=1;i<=n;i++){
        cin>>s;
        for (int j=1; j<=30; j++)
            hash[i][j] = (hash[i][j-1]*31 + (s[j-1] -'a'+1)) % MOD;
    }
    ll ans=0;
    ll l=1, r=30;
    ll test=0;
    while (l<=r){
        ll mid=(l+r)/2;
        bool flag=false;
        vector<ll> v;
        for (int i=1;i<=n;i++){
            map<ll,bool>m;
            for (int j=1;j+mid-1<=30;j++){
                ll x=getHash(i,j,j+mid-1);
                if (m[x]==0) v.pb(x), m[x]=1;
            }
        }
        test += v.size();
        if (test==1e5) break;
        sort(all(v));
        ll cnt=1;
        for (int i=1;i<v.size();i++){
            if (v[i]==v[i-1]){
                cnt++;
                if (cnt==k){
                    flag = true;
                    break;
                }
            }
            else{
                if (cnt==k){
                    flag = true;
                    break;
                }
                else if ((int)v.size()-i+2<k) break;
                else cnt=1;
            }
        }
        if (cnt>=k) flag = true;
        if (flag) ans=max(ans,mid), l=mid+1;
        else r=mid-1;
    }
    if (ans==0) cout<<-1; else cout<<ans;
    
    return 0;
}