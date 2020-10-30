#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define pp push
#define et empty
#define mp make_pair
typedef int64_t ll;
typedef uint64_t ull;
// ll mulmod(ll a,ll b,ll c)
// {
//     ll x = 0 , y = a%c ;
//     while(b>0)
//     {
//         if(b%2) x = (x+y)%c ;
//         y=(y*2)%c;
//         b/=2;
//     }
//     return x%c ;
// }
// /* Calculate ( a^b ) %c */
// ll modulo(ll a,ll b,ll c)
// {
//     ll x = 1 , y = a%c ;
//     while( b > 0 )
//     {
//         if(b%2) x = mulmod(x,y,c) ;
//         y=mulmod(y,y,c);
//         b/=2;
//     }
//     return x%c ;
// }
// bool miller_rabin(ll p, ll iteration)
// {
//     if(p<2) return false ;
//     if(p%2==0&&p!=2) return false ;
//     ll s = p-1 ;
//     while(s%2==0) s/=2;
//     for(ll i=1;i<=iteration;i++)
//     {
//         ll a = rand() % (p-1)+1 , temp = s ;
//         ll mod = modulo(a,temp,p);
//         while(mod!=1&&mod!=p-1&&temp!=p-1)
//         {
//             mod = mulmod(mod,mod,p);
//             temp*=2;
//         }
//         if(temp%2==0&&mod!=p-1) return false ;
//     }
//     return true ;
// }
int main(){
	freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll a,b=0;
    // vector<int> ar;
    // cin>>a;
    // ll aaa = a;
    // int k=a%10;
    // while((k!=3 || k!=4 || k!=7) && a>0){
    // 	ar.pb(a%10);
    // 	k = a%10;
    // 	if(k==3 || k==4 || k==7){
	   //  	cout<<"no";
	   //  	return 0;
	   //  }
    // 	a/=10;
    // }
    // if(k==3 || k==4 || k==7){
    // 	cout<<"no";
    // 	return 0;
    // }
    // for(int i=0; i<ar.size(); i++){
    // 	if(ar[i]==6){
    // 		b=b*10+9;
    // 	}
    // 	else if(ar[i]==9){
    // 		b=b*10+6;	
    // 	}
    // 	else b=b*10+ar[i];
    // }
    // // cout<<b;
    // if(miller_rabin(aaa,50) && miller_rabin(b,50)) puts("yes");
    //     else puts("no");
    return 0;	

}