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

class SegmentTree{
    public:
    int n;
    vi tree, arr;

    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2 * node, left, mid);
        build(arr, 2 * node + 1, mid + 1, right);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int rangeQry(int node, int left, int right, int l, int r){
        if(r < left || right < l){
            return 0;
        }
        if(l <= left && right <= r){
            return tree[node];
        }
        int mid = (left + right) / 2;
        int leftSum = rangeQry(2 * node, left, mid, l, r);
        int rightSum = rangeQry(2 * node + 1, mid + 1, right, l, r);
        return leftSum + rightSum;
    }
    int qry(int l, int r){
        return rangeQry(1, 0, n - 1, l, r);
    }
    void solve(){
        cin >> n;
        arr.resize(n);
        for(int i = 0 ; i < n ; i++){
            int x; cin >> x;
            arr[i] = x;
        }
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
        cout << qry(0, 2) << " \n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    SegmentTree st;
    // int t;
    // cin >> t;
    // while (t--) {
    //     st.solve();
    // }
    st.solve();
    return 0;
}