#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;
typedef vector<vector<long long>> matrix;

matrix matmul(matrix a, matrix b) {
    int n = a.size();
    matrix ans(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < a.size(); k++) {
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j]) % M;
            }
        }
    }

    return ans;
}

matrix matpow(matrix a, long long k) {
    if (k == 1) return a;

    matrix tmp = matpow(a, k/2);
    tmp = matmul(tmp, tmp);

    if (k % 2) return matmul(tmp, a);
    else return tmp;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k, u, v; cin >> n >> k >> u >> v; u--; v--;
    matrix adj(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    adj = matpow(adj, k);

    cout << adj[u][v] << '\n';

    return 0;
}