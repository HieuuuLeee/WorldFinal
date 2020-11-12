/*  よろしくお願いします
*/
#include <bits/stdc++.h>
using namespace std;

#define DB(_x) cout << #_x << " is " << (_x) << "\n";
#define fs first
#define sc second
#define pb push_back

using LL = long long;
using LD = long double;
using VI = vector<int>;
using PI = pair<int, int>;
using PPI = pair<int, PI>;
const int mod = 1e9 + 7;
const int Dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int Dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct Node {
  int lazy;
  int mn, argmn;
};

// BEG: GLOBAL VARIABLES
int n, bk, m;
vector<vector<Node>> A(2, vector<Node>(4000000));
VI B;
// END: GLOBAL VARIABLES

void UP(int idx, int type) {
  int vlmn = A[type][(idx * 2)].mn;
  int vrmn = A[type][(idx * 2) + 1].mn;
  if (vlmn <= vrmn) {
    A[type][idx].mn = vlmn;
    A[type][idx].argmn = A[type][(idx * 2)].argmn;
  } else {
    A[type][idx].mn = vrmn;
    A[type][idx].argmn = A[type][(idx * 2) + 1].argmn;
  }
}

void BUILD(int idx, int tl, int tr, int type) {
  if (tl == tr) {
    A[type][idx].lazy = 0;
    A[type][idx].argmn = tl;
    A[type][idx].mn = type ? -B[tl] : B[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  BUILD((idx * 2), tl, tm, type);
  BUILD((idx * 2) + 1, tm + 1, tr, type);
  UP(idx, type);
}

void DOWN(int idx, int type) {
  int val = A[type][idx].lazy;
  A[type][(idx * 2)].lazy += val;
  A[type][(idx * 2)].mn += val;
  A[type][(idx * 2) + 1].lazy += val;
  A[type][(idx * 2) + 1].mn += val;
  A[type][idx].lazy = 0;
}

void UPDATE(int idx, int tl, int tr, int ql, int qr, int val, int type) {
  if (qr < tl || tr < ql) return;
  if (ql <= tl && qr >= tr) {
    A[type][idx].mn += val;
    A[type][idx].lazy += val;
    return;
  }

  DOWN(idx, type);

  int tm = (tl + tr) >> 1;
  UPDATE((idx * 2), tl, tm, ql, min(qr, tm), val, type);
  UPDATE((idx * 2) + 1, tm + 1, tr, max(ql, tm + 1), qr, val, type);

  UP(idx, type);
}

int GET(int idx, int tl, int tr, int ql, int qr, int type) {
  if (qr < tl || tr < ql) {
    return -1;
  }
  if (ql <= tl && tr <= qr) {
    return idx;
  }
  int tm = (tl + tr) >> 1;
  DOWN(idx, type);

  int argl = GET((idx * 2), tl, tm, ql, qr, type);
  int argr = GET((idx * 2) + 1, tm + 1, tr, ql, qr, type);

  if (argr == -1 || argl != -1 && A[type][argl].mn <= A[type][argr].mn)
    return argl;
  return argr;
}

void Excalibur() {
  cin >> n >> bk >> m;
  B.resize(n);
  for (int &x : B) {
    cin >> x;
  }
  BUILD(1, 0, n - 1, 0);
  BUILD(1, 0, n - 1, 1);
  for (int i = 0; i < m; ++i) {
    int idxMn = GET(1, 0, n - 1, 0, n - 1, 0);
    if (A[0][idxMn].mn >= 30000001) break;
    UPDATE(1, 0, n - 1, max(0, A[0][idxMn].argmn - bk), min(n - 1, A[0][idxMn].argmn + bk), 1, 0);
    UPDATE(1, 0, n - 1, max(0, A[0][idxMn].argmn - bk), min(n - 1, A[0][idxMn].argmn + bk), -1, 1);

    int idxMx = GET(1, 0, n - 1, 0, n - 1, 1);
    UPDATE(1, 0, n - 1, max(0, A[1][idxMx].argmn - bk), min(n - 1, A[1][idxMx].argmn + bk), 30000001, 0);
    UPDATE(1, 0, n - 1, max(0, A[1][idxMx].argmn - bk), min(n - 1, A[1][idxMx].argmn + bk), 30000001, 1);
  }

  int idxMx = GET(1, 0, n - 1, 0, n - 1, 1);
  if (A[1][idxMx].mn >= 1) cout << 0;
  else cout << -A[1][idxMx].mn;
}

// #define IOFILE

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef IOFILE
  freopen("INPUT.in", "r", stdin);
  freopen("OUTPUT.out", "w", stdout);
#endif

  Excalibur();
  return 0;
}