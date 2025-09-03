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
#define MAX_N 100001
#define MAX_L 18
#define MOD 1000000007
#define INF 1000000000LL
#define LMOD 1000000000000000007LL

int n, q;
ll ft1[MAX_N], ft2[MAX_N];

void update(ll *ft, int i, ll val){
    while(i <= n){
        ft[i] += val;
        i += (i & -i);
    }
}

void range_update(int l, int r, ll val) {
  update(ft1, l , val);
  update(ft1, r + 1, -val);
  update(ft2, l , val * (l - 1));
  update(ft2, r + 1, -val * r);
}

ll sum(ll *ft, int i){
    ll ans = 0;
    while(i > 0){
        ans += ft[i];
        i -= (i & -i);
    }
    return ans;
}

ll rangeSum(int i){
    return sum(ft1, i) * i - sum(ft2, i);
}

ll qry(int l, int r){
    return rangeSum(r) - rangeSum(l - 1);
}

void solve() {
  memset(ft1, 0, sizeof ft1);
  memset(ft2, 0, sizeof ft2);
  cin >> n >> q;
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 0) {
      int val;
      cin >> val;
      range_update(l, r, val);
    } else {
      cout << qry(l, r) << "\n";
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