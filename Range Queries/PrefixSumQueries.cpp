#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    ll sum;
    ll maxPrefixVal;
};

class SegmentTree {
    int n;
    vector<node> tree;
    
    node combine(node left, node right) {
        node res;
        res.sum = left.sum + right.sum;
        res.maxPrefixVal = max(left.maxPrefixVal, left.sum + right.maxPrefixVal);
        return res;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, {0, 0});
    }
    
    void update(int idx, ll val, int i, int l, int r) {
        if (l == r) {
            tree[i].sum = val;
            tree[i].maxPrefixVal = max(0LL, val);
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(idx, val, 2 * i + 1, l, mid);
        } else {
            update(idx, val, 2 * i + 2, mid + 1, r);
        }
        
        tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);          
    }
    
    node query(int start, int end, int i, int l, int r) {
        if (r < start || l > end) return {0, 0};
        if (start <= l && r <= end) return tree[i];
        

        int mid = l + (r - l) / 2;
        node leftChild = query(start, end, 2 * i + 1, l, mid);
        node rightChild = query(start, end, 2 * i + 2, mid + 1, r);
        
        return combine(leftChild, rightChild);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n);
    SegmentTree st(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        st.update(i, nums[i], 0, 0, n - 1);
    }
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            k--;
            st.update(k, u, 0, 0, n - 1);
        } else {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << st.query(a, b, 0, 0, n - 1).maxPrefixVal << "\n";
        }
    }
    
    return 0;
}