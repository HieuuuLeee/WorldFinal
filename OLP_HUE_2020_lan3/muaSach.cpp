#include <bits/stdc++.h> 
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
#define prarr(a,n)            For(i,1,n)cout<<a[i]<<" "; brln;
#define bitcount(n)         __builtin_popcountll(n)

#define INFILE(name)      freopen(name, "r", stdin)
#define OUFILE(name)      freopen(name, "w", stdout)
#define fast              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#include<bits/stdc++.h> 
using namespace std; 
int KnapSack(int val[], int wt[], int n, int W) 
{ 
    int mat[2][W+1]; 
    memset(mat, 0, sizeof(mat)); 
    int i = 0; 
    while (i < n)
    { 
        int j = 0;
        if (i%2!=0) 
        { 
            while (++j <= W) // check for each value 
            { 
                if (wt[i] <= j) // include element 
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]], 
                                    mat[0][j] ); 
                else           // exclude element 
                    mat[1][j] = mat[0][j]; 
            } 
  
        } 
  
        else
        { 
            while(++j <= W) 
            { 
                if (wt[i] <= j) 
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]], 
                                     mat[1][j]); 
                else
                    mat[0][j] = mat[1][j]; 
            } 
        } 
        i++; 
    } 
  
    return (n%2 != 0)? mat[0][W] : mat[1][W]; 
} 
int main(){ 
    // INFILE("in.txt");
    // OUFILE("out.txt");
    int nn, W;
    cin>>nn>>W;
    int val[nn+1];
    int wt[nn+1];
    For(i,0,nn-1) cin>>wt[i];
    For(i,0,nn-1) cin>>val[i];
    cout << KnapSack(val, wt, nn, W); 
    return 0; 
} 