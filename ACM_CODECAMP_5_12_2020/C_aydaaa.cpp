#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<pair<ll, ll>> c;
vector<ll> p;
vector<ll> res;
map<ll,ll> check;
int main(){
    // freopen("../in.txt", "r", stdin);
    // freopen("../out.txt", "w", stdout);
    ll n,m;
    cin >> n;
    for(ll i = 0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        c.push_back(make_pair(x,y));
    }
    sort(c.begin(),c.end());
    cin>>m;
    for(ll i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        check[tmp]=1;
        p.push_back(tmp);
    }
    sort(p.begin(),p.end());
    for(int i=0; i<n; i++){
        int dem = (upper_bound(p.begin(),p.end(),c[i].second)-p.begin()) - (lower_bound(p.begin(),p.end(),c[i].first)-p.begin()) + (upper_bound(res.begin(),res.end(),c[i].second)-res.begin()) - (lower_bound(res.begin(),res.end(),c[i].first)-res.begin());
        // cout<<dem<<"\n";
 
        if(dem>2){
            cout<< "impossible";
            return 0;
        }
        else if(dem==2){
            continue;
        }
        if(dem==0){
            int k = c[i].first+1;
            while(check[k]==1){
                k++;
            }
            res.push_back(k);
            dem++;
        }        
        if(dem==1 && i!=n-1){
            if((upper_bound(p.begin(),p.end(),c[i+1].second)-p.begin()) - (lower_bound(p.begin(),p.end(),c[i+1].first)-p.begin()) + (upper_bound(res.begin(),res.end(),c[i+1].second)-res.begin()) - (lower_bound(res.begin(),res.end(),c[i+1].first)-res.begin()) < 2 && c[i].second >= c[i+1].first){
                if(check[c[i].second]==0)
                    res.push_back(c[i].second);
                else{
                    int k = c[i].first+1;
                    while(check[k]==1){
                        k++;
                    }
                    res.push_back(k);
                    dem++;
                }
            }
            else{
                int k = c[i].second-1;
                while(check[k]==1){
                    k--;
                }
                res.push_back(k);
                dem++;
            }
        }
        else if(dem==1){
            int k = c[i].second-1;
            while(check[k]==1){
                k--;
            }
            res.push_back(k);
            dem++;
        }
    }
    int ress = res.size();
    cout<<ress<<"\n";
    for(auto i:res) cout<<i<<" ";
 
    return 0;
}