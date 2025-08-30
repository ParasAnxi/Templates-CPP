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
#define MAX_N 1005
#define MOD 1000000007
#define INF 1000000000LL
#define LMOD 1000000000000000007LL

int n, q;
int ft[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];

void update(int x, int y, int val) {
  int tx = x;
  while (tx <= n) {
    int ty = y;
    while (ty <= n) {
      ft[tx][ty] += val;
      ty += (ty & -ty);
    }
    tx += (tx & -tx);
  }
}

int sum(int x, int y) {
  int ans = 0;
  int tx = x;
  while (tx > 0) {
    int ty = y;
    while (ty > 0) {
      ans += ft[tx][ty];
      ty -= (ty & -ty);
    }
    tx -= (tx & -tx);
  }
  return ans;
}

int qry(int x1, int y1, int x2, int y2) {
  return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '*') {
        update(i, j, 1);
      }
    }
  }
  while (q--) {
    char c;
    cin >> c;
    if (c == '1') {
      int x, y;
      cin >> x >> y;
      if (grid[x][y] == '*') {
        update(x, y, -1);
        grid[x][y] = '.';
      } else {
        update(x, y, 1);
        grid[x][y] = '*';
      }
    } else {
      int x1, x2, y1, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << qry(x1, y1, x2, y2) << "\n";
    }
  }
}
int main() {
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
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