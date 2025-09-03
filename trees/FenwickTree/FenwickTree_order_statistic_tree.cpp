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
int ft[MAX_N];

void update(int i, int val) {
  while (i <= n) {
    ft[i] += val;
    i += (i & -i);
  }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans += ft[i];
        i -= (i & -i);
    }
    return ans;
}
int find_by_order(int k){
    int sum = 0, pos = 0;
    for(int i = MAX_L; i >= 0; i--){
        if(pos + (1 << i) < MAX_N && sum + ft[pos + (1 << i)] < k){
            sum += ft[pos + (1 << i)];
            pos += (1 << i);
        }
    }
    return pos + 1;
}

void solve() {
  memset(ft, 0, sizeof ft);
  cin >> n >> q;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    update(arr[i], 1);
  }
  while(q--){
    char c;
    cin >> c;
    if(c == '!'){
        int k, x;
        cin >> k >> x;
        k--;
        update(arr[k], -1);
        arr[k] = x;
        update(arr[k], 1);
    }
    else{
        int a , b;
        cin >> a >> b;
        cout << sum(b) - sum(a - 1) << "\n";
    }
  }
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