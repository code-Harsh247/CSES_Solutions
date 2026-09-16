#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

struct node {
    int h;
    int visible;
    node(int a, int b) : h(a), visible(b) {}
};

class SegmentTree {
    int n;
    vector<node> tree;

    int combineVisible(int height, int i, int l, int r) {
        if (tree[i].h <= height) return 0;
        if (l == r) return 1;
        
        int mid = l + (r - l) / 2;
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        
        if (tree[left_child].h <= height) {
            // Skip the left child entirely, only search the right child
            return combineVisible(height, right_child, mid + 1, r);
        } else {
            // Search the left child.
            int visible_in_left = combineVisible(height, left_child, l, mid);
            // Right child surviving buildings is a pre-calculated difference
            int surviving_in_right = tree[i].visible - tree[left_child].visible;
            
            return visible_in_left + surviving_in_right;
        }
    }

    // Fixed the parameter typo: right_ri -> right_r
    node combineNodes(node left, node right, int right_i, int right_l, int right_r) {
        int maxH = max(left.h, right.h);
        int visible = left.visible + combineVisible(left.h, right_i, right_l, right_r);
        return node(maxH, visible);
    }

    // Internal query function that passes current_max by reference
    int queryUtil(int ql, int qr, int& current_max, int i, int l, int r) {
        // If the current node is completely inside the query range
        if (ql <= l && r <= qr) {
            int visible = combineVisible(current_max, i, l, r);
            current_max = max(current_max, tree[i].h); // update the running max
            return visible;
        }
        
        int mid = l + (r - l) / 2;
        int ans = 0;
        
        // We must process left child BEFORE right child to simulate left-to-right visibility
        if (ql <= mid) {
            ans += queryUtil(ql, qr, current_max, 2 * i + 1, l, mid);
        }
        if (qr > mid) {
            ans += queryUtil(ql, qr, current_max, 2 * i + 2, mid + 1, r);
        }
        
        return ans;
    }

public:
    SegmentTree(int size) {
        n = size;
        // Changed INF to 0 so empty nodes don't block visible buildings
        tree.assign(4 * n, node(0, 0));
    }

    void update(int idx, int val, int i, int l, int r) {
        if (l == r) {
            tree[i].h = val;
            tree[i].visible = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(idx, val, 2 * i + 1, l, mid);
        } else {
            update(idx, val, 2 * i + 2, mid + 1, r);
        }
        tree[i] = combineNodes(tree[2 * i + 1], tree[2 * i + 2], 2 * i + 2, mid + 1, r);
    }

    // Public wrapper for range queries
    int query(int ql, int qr, int l, int r) {
        int current_max = 0; // Represents the max height seen so far (from the left)
        return queryUtil(ql, qr, current_max, 0, l, r);
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    SegmentTree st(n);

    // Assuming 0-indexed arrays for input
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        st.update(i, h, 0, 0, n - 1);
    }

    // Process queries
// Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        a--; b--; // Adjust to 0-indexed for our Segment Tree
        
        cout << st.query(a, b, 0, n - 1) << "\n";
    }

    return 0;
}