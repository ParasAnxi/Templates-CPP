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
#define MAX_N 100005
#define MOD 1000000007
#define INF 1000000000LL
#define LMOD 1000000000000000007LL

class Graph {
public:
  vi adj[MAX_N];
  int V, E;
  vi visited;
  vi vDfs;
  Graph(int V, int E) {
    this->V = V;
    this->E = E;
    visited.assign(V + 1, 0);
    vDfs.clear();
  }
  void init(int u, int v, int directed) {
    adj[u].pb(v);
    if (!directed) {
      adj[v].pb(u);
    }
  }
  void solveDFS(int node) {
    visited[node] = 1;
    vDfs.pb(node);
    for (auto &v : adj[node]) {
      if (!visited[v]) {
        solveDFS(v);
      }
    }
  }
};
void solve() {
  int V, E;
  cin >> V >> E;
  Graph g(V, E);
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    g.init(u, v, 0);
  }
  g.vDfs.clear();
  for (int i = 0; i < V; i++) {
    if (!g.visited[i]) {
      g.solveDFS(i);
    }
  }
  for (auto &i : g.vDfs) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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