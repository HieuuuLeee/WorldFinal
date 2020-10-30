#include <bits/stdc++.h>
 
#define INF (int)2e9
#define EPS 1e-8
#define pb push_back
#define pause system("pause")
#define exit exit(0)
#define endl '\n'
 
using namespace std;
using ull = unsigned long long;
using ll = long long;
 
typedef pair<int, int> pii;
const int N = 200005, K = 1000005, SZ = 1 << 9, MOD = 998244353;
 
int t, n, a[N], cnt[K];
pair<pii, int> q[N];
ll ans[N];
 
ll sm = 0;
void add(int x, int f = 1) {
	sm -= (ll)cnt[x] * cnt[x] * x;
	cnt[x] += f;
	sm += (ll)cnt[x] * cnt[x] * x;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
 
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
 
	for (int i = 0; i < t; ++i) {
		cin >> q[i].first.first >> q[i].first.second;
		q[i].second = i;
	}
 
	sort(q, q + t, [](auto a, auto b) {
		if (a.first.first / SZ == b.first.first / SZ) {
			return ((a.first.first / SZ) & 1) ? a.first.second > b.first.second : a.first.second < b.first.second;
		}
 
		return a.first.first / SZ < b.first.first / SZ;
	});
 
	int l = 0, r = -1;
	for (int i = 0; i < t; ++i) {
		int nl = q[i].first.first, nr = q[i].first.second;
		while (l < nl) {
			add(a[l++], -1);
		}
 
		while (l > nl) {
			add(a[--l]);
		}
 
		while (r < nr) {
			add(a[++r]);
		}
 
		while (r > nr) {
			add(a[r--], -1);
		}
 
		ans[q[i].second] = sm;
	}
 
	for (int i = 0; i < t; ++i) {
		cout << ans[i] << endl;
	}
	//pause;
	return 0;
}