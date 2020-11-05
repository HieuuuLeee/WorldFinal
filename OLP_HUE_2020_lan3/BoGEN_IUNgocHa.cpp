#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <map>

using namespace std;

#define X first
#define Y second
const int N = 3e4 + 10;
long long n, k, a[N][35], F[N][35], pow4[N];

long long Sum(int x, int i, int L)
{
    int j = i + L - 1;
    return F[x][j] - F[x][i - 1] * pow4[L];
}

typedef pair <long long, int> ill;

unordered_map <long long, int> Map;
unordered_map <long long, bool > Map2;
bool check(int L)
{
    Map.clear();
    for (int i = 1; i <= n; i++) {
        Map2.clear();
        for (int j = 1; j + L - 1 <= 30; j++) {
            long long S = Sum(i, j, L);
            if (Map2[S]) continue;
            else {
                Map2[S] = true;
                Map[S]++;
                if (Map[S] >= k) return true;
            }
        }
    }
    return false;
}

void Solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char x;
        for (int j = 1; j <= 30; j++) {
            cin >> x;
            if (x == 'A') a[i][j] = 1;
            else if (x == 'C') a[i][j] = 2;
            else if (x == 'G') a[i][j] = 3;
            else a[i][j] = 4;
            F[i][j] = F[i][j - 1] * 5 + a[i][j];
        }
    }
    pow4[0] = 1;
    for (int i = 1; i <= 30; i++) pow4[i] = pow4[i - 1] * 5;
    int l = 1, r = 30, ans = -1;
    if (n >= 10000) r = 15;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;

}

int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
    #define task "test"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
    #endif // ONLINE_JUDGE
    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }
}