#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MAX_N 200001
#define MAX_L 18
#define MOD 1000000007
#define INF 1000000000LL
#define LMOD 1000000000000000007LL

int n, q;
ll ft[MAX_N];

void update(int i, int val) {
  while (i <= n) {
    ft[i] += val;
    i += (i & -i);
  }
}

void range_update(int l, int r, int val) {
  update(l, val);
  update(r + 1, -val);
}

ll sum(int i) {
  ll ans = 0;
  while (i > 0) {
    ans += ft[i];
    i -= (i & -i);
  }
  return ans;
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    range_update(i, i, x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, val;
      cin >> l >> r >> val;
      range_update(l, r, val);
    } else {
      int x;
      cin >> x;
      cout << sum(x) << "\n";
    }
  }
}
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  // solve();
  return 0;
}