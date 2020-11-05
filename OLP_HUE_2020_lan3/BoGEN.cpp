#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int val(char &c) {
	if (c == 'A') return 0;
	else if (c == 'T') return 1;
	else if (c == 'G') return 2;
	else return 3;
}

unordered_map<long long, int> mp;
unordered_set<long long> st;

bool check(int n, int k, vector<string> &ss, int len) {
	mp.clear();

	long long vl = (1LL << (len*2)) - 1;

	for (string &s: ss) {
		st.clear();
		long long hs = 0;
		for (int i = 0; i < len; i++) {
			hs <<= 2;
			hs += val(s[i]);
		}
		st.insert(hs);

		for (int i = len; i < 30; i++) {
			hs <<= 2;
			hs += val(s[i]);
			hs &= vl;
			st.insert(hs);
		}

		for (long long i: st) {
			mp[i]++;
			if (mp[i] >= k) {
				return 1;
			}
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int lo = 0, hi = 30;
	while (lo < hi) {
		int mid = (lo + hi + 1)/2;

		if (check(n, k, s, mid)) {
			lo = mid;
		} else {
			hi = mid-1;
		}
	}	
	if (lo == 0) lo = -1;
	cout << lo << '\n';
	
	return 0;
}