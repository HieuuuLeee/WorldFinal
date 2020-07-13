#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> a;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll n,xuoi=0,nguoc=0;
    cin >> n;
    for(int i =0;i<n;i++){
        ll tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    int i=0,j=i+1;
    ll ma1=0;
    while(a[i]<a[j] && j<n) {i++;j++;}
    if(j==n){
        cout<<1<<" "<<1;
        return 0;
    }
    ma1=max(ma1,a[i]);
    while(a[j]<=a[i] && a[j]<=a[j-1] && j<n) {
        ma1 = max(ma1,a[j]);
        j++;
    }
    if(j==n){
        cout<<i+1<<" "<<j;
        return 0;
    }
    int k=j+1;
    if(a[k-1]<ma1){
        cout<<"impossible";
        return 0;
    }
    while(a[k]>=a[k-1] && k<n) k++;
    if(k<n){
        cout<<"impossible";
        return 0;
    }

    // reverse(a.begin(),a.end());
    // int ii=0,jj=ii+1;
    // while(a[ii]<a[jj] && jj<n) {ii++;jj++;}
    // if(jj==n){
    //     cout<<1<<" "<<1;
    //     return 0;
    // }
    // while(a[jj]<=a[ii] && a[jj]<=a[jj-1] && jj<n) jj++;
    // if(jj==n){
    //     cout<<ii+1<<" "<<jj;
    //     return 0;
    // }
    // int kk=jj+1;
    // while(a[kk]>=a[kk-1] && kk<n) kk++;
    // if(kk<n){
    //     nguoc=-1;
    //     // return 0;
    // }
    // if(xuoi==-1 && nguoc==-1){
    //     cout<<"impossible";
    //     return 0;
    // }
    // if(xuoi!=-1){

    //     cout<<i+1<<" "<<j;
    //     return 0;
    // }
    cout<<i+1<<" "<<j;
    // cout<<n-jj+1<<" "<<n-ii;
    // while(ind<n-1 && a[ind]<=a[ind+1]) ind++;
    // be=ind;
    // if(ind==n-1){
    //     cout<<1<<" "<<1;
    //     return 0;
    // }
    // while(ind<n-1 && a[ind]>a[ind+1]) ind++;
    // en = ind;
    // ind++;
    // while(ind<n){
    //     if(a[ind]<a[ind-1]){
    //         cout<<"impossible";
    //         return 0;
    //     } 
    // }
    // cout<<be<<" "<<en;
    return 0;
}