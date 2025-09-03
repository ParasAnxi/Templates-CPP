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
    struct Node{
        ll sum;
        int mini;
        int maxi;
        int gcd_v;
        int xor_v;
        Node(){
            sum = 0;
            mini = INT_MAX;
            maxi = INT_MIN;
            gcd_v = 0;
            xor_v = 0;
        }
    };
    int n;
    vector<Node> tree;
    vi arr;

    Node merge(Node &a, Node &b) {
      Node ans;
      ans.sum = a.sum + b.sum;
      ans.mini = min(a.mini, b.mini);
      ans.maxi = max(a.maxi, b.maxi);
      ans.gcd_v = __gcd(a.gcd_v, b.gcd_v);
      ans.xor_v = a.xor_v ^ b.xor_v;
      return ans;
    }

    void build(int node,int left, int right){
        if(left == right){
            tree[node].sum = arr[left];
            tree[node].mini = arr[left];
            tree[node].maxi = arr[left];
            tree[node].gcd_v = arr[left];
            tree[node].xor_v = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    Node rangeQry(int node, int left, int right, int l, int r){
        if(r < left || right < l){
            return Node();
        }
        if(l <= left && right <= r){
            return tree[node];
        }
        int mid = (left + right) / 2;
        Node leftAns = rangeQry(2 * node, left, mid, l, r);
        Node rightAns = rangeQry(2 * node + 1, mid + 1, right, l, r);
        return merge(leftAns, rightAns);
    }
    
    Node qry(int l, int r){
        return rangeQry(1, 0 , n - 1, l , r);
    }

    void update(int node, int left, int right, int idx, int val){
        //point increment
        if(left == right){
            arr[idx] += val;
            tree[node].sum = arr[idx];
            tree[node].mini = arr[idx];
            tree[node].maxi = arr[idx];
            tree[node].gcd_v = arr[idx];
            tree[node].xor_v = arr[idx];
            return;
        }
        //point update
        // if(left == right){
        //     arr[idx] = val;
        //     tree[node].sum = val;
        //     tree[node].mini = val;
        //     tree[node].maxi = val;
        //     tree[node].gcd_v = val;
        //     tree[node].xor_v = val;
        //     return;
        // }
        int mid = (left + right) / 2;
        if(idx <= mid){
            update(2 * node, left, mid, idx, val);
        }else{
            update(2 * node + 1, mid + 1, right, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void solve(){
        cin >> n;
        arr.assign(n, 0);
        tree.assign(4 * n, Node());
        for(int i = 0 ; i < n ; i++){
            int x; cin >> x;
            arr[i] = x;
        }
        build(1, 0, n - 1);
        cout << qry(0, 4).sum <<"\n";
        update(1, 0, n - 1, 2, 10);
        cout << qry(0, 4).sum <<"\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    SegmentTree st;
    st.solve();
    return 0;
}