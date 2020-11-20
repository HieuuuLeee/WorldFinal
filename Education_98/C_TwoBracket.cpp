// https://codeforces.com/contest/1452/problem/C
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

long long ans[1000005];
bool check(char s, char ss){
    return ((s=='(' && ss==')') || (s=='[' && ss ==']'));
}
int main() {
    fast;
    INFILE("../in.txt");
    OUFILE("../out.txt");
    int t;
    cin>>t; //cout<<t;
    while(t--){
        // cout<<"*\n";
        string s; cin>>s;
        stack<char> st1,st2;
        // bool flag = false;
        int ans = 0;
        // st.push(s[0]);
        // cout<<s<<"\n";
        For(i,0,s.length()-1){
            switch (s[i]){
                case '(':
                    // cout<<s[i]<<"\n";
                    st1.push(s[i]);
                    break;
                case '[':
                    // cout<<s[i]<<"\n";
                    st2.push(s[i]);
                    break;
                case ')':
                    // cout<<s[i]<<"\n";
                    if(!st1.et() && st1.top() == '(') {++ans; st1.pop();}
                    else st1.push(s[i]);
                    break;
                case ']':
                    // cout<<s[i]<<"\n";
                    if(!st2.et() && st2.top()=='[') {++ans; st2.pop();}
                    else st2.push(s[i]);
                    break; 
                default:
                    break;   
            }
        }
        cout<<ans<<"\n";
    }
}
Từ lúc thầy, cô dẫn dắt những anh chị đầu đàn, đến khi có những tấm bằng khen đầu tiên, niềm vui đó quả là khó tả biết bao nhiêu đối với người thầy giáo, cô giáo mang trọng trách này.