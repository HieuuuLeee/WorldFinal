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

const ll MOD = 1000000007;
const int MAX = 1000005;
  


// int max(int a, int b);  
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )  
{  
    pair<int,pair<int,int>> L[m + 1][n + 1];  
    int i, j;  
    int ans=0;
      
    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0){
            L[i][j].fi = 0;  
            L[i][j].se.fi = -5;
            L[i][j].se.se = -5;
        }  
      
        else if (X[i - 1] == Y[j - 1] && (abs((i-1)-L[i-1][j-1].se.fi)+abs((j-1)-L[i-1][j-1].se.se))<4)  {
            L[i][j].fi = L[i - 1][j - 1].fi + 1;  
            L[i][j].se.fi = i-1;
            L[i][j].se.se = j-1;
        }
        else if(X[i - 1] == Y[j - 1]){
            L[i][j].fi = 4;
            L[i][j].se.fi = i-1;
            L[i][j].se.se = j-1;   
        }
        else{
            if((L[i - 1][j].fi-abs((i-1)-L[i-1][j].se.fi)-abs((j-1)-L[i-1][j].se.se)) < (L[i][j - 1].fi-abs((i-1)-L[i][j-1].se.fi)-abs((i-1)-L[i][j-1].se.se))){
                L[i][j].fi  = L[i-1][j].fi;
                L[i][j].se.fi = L[i-1][j].se.fi;
                L[i][j].se.se = L[i-1][j].se.se;
            }  
            else{
                L[i][j].fi  = L[i][j-1].fi;
                L[i][j].se.fi = L[i][j-1].se.fi;
                L[i][j].se.se = L[i][j-1].se.se;
            }
        }
        ans=max(ans,L[i][j].fi);
        }  
    }  
    For(i,0,m){
        For(j,0,n) cout<<L[i][j].fi<<":"<<L[i][j].se.fi<<":"<<L[i][j].se.se<<" ";cout<<"\n";
    }
          
    /* L[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
    return ans; 
} 
  
/* Utility function to get max of 2 integers */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Driver code */
int main()  
{  
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int n,m; cin>>n>>m;
    char X[n+1];  
    char Y[m+1];
    cin>>X>>Y;
    // int m = strlen(X);  
    // int n = strlen(Y);  
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;  
      
    return 0;  
} 