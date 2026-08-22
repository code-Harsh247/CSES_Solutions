#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;



class RangeMaxIndexTree {
private:
    ll n;
    const vector<ll>& arr; // Keep a reference to the original array for values
    vector<ll> tree;       // Stores indices

    // Helper to compare two indices and return the one with the larger value
    ll getBetterIndex(ll idx1, ll idx2) {
        if (idx1 == -1) return idx2;
        if (idx2 == -1) return idx1;
        return (arr[idx1] >= arr[idx2]) ? idx1 : idx2;
    }

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = start; // Leaf node stores its own index
            return;
        }
        ll mid = start + (end - start) / 2;
        ll left = 2 * node + 1;
        ll right = 2 * node + 2;

        build(left, start, mid);
        build(right, mid + 1, end);

        // Store the index that holds the maximum value
        tree[node] = getBetterIndex(tree[left], tree[right]);
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        // Case 1: Out of range
        if (r < start || end < l) {
            return -1; 
        }
        // Case 2: Completely inside range
        if (l <= start && end <= r) {
            return tree[node];
        }
        // Case 3: Partial overlap
        ll mid = start + (end - start) / 2;
        ll leftIndex = query(2 * node + 1, start, mid, l, r);
        ll rightIndex = query(2 * node + 2, mid + 1, end, l, r);

        return getBetterIndex(leftIndex, rightIndex);
    }

    void update(ll node, ll start, ll end, ll idx) {
        if (start == end) {
            // Leaf node index stays the same, but underlying value in 'arr' changed
            return;
        }
        ll mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx);
        } else {
            update(2 * node + 2, mid + 1, end, idx);
        }
        // Re-evaluate the best index on the way back up
        tree[node] = getBetterIndex(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    // Pass the original array by reference
    RangeMaxIndexTree(const vector<ll>& inputArr) : arr(inputArr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Returns the index of the maximum element in range [l, r]
    ll rangeMaxIndex(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }

    // Call this AFTER you modify the value in your original array
    void pollUpdate(ll idx) {
        update(0, 0, n - 1, idx);
    }
};

// Pass parent_val to validate jumps, and a reference to max_visited to track the global best
ll solve(vector<ll>& mountains, ll l, ll r, RangeMaxIndexTree& st, ll parent_val) {
    if(l > r) return 0;
    
    ll peak = st.rangeMaxIndex(l, r);
    
    // Calculate the maximum paths in the left and right subtrees
    ll left = solve(mountains, l, peak - 1, st, mountains[peak]);
    ll right = solve(mountains, peak + 1, r, st, mountains[peak]);

    ll max_child = max(left, right);

    // If this mountain is the same height as its parent, it's a duplicate max.
    // It is not a valid jump from the parent, so we do NOT add 1.
    // BUT we still return max_child to transparently pass up the valid 
    // routes found in its sub-arrays.
    if(mountains[peak] == parent_val) {
        return max_child; 
    }

    // It is strictly smaller, so jumping here counts as a visited mountain!
    return 1 + max_child;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> mountains(n);
    for(ll i = 0; i < n; i++) cin >> mountains[i];
    
    RangeMaxIndexTree st(mountains);

    // The root call naturally explores all top-level peaks and returns the max.
    ll ans = solve(mountains, 0, n - 1, st, LLONG_MAX);
    
    cout << ans << "\n";

    return 0;
}