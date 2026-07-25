#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define PBDS to hold pair<int, int>
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
    int start, end, index;
};

// Sort: start ASCENDING, end DESCENDING
bool compareRanges(const Range& a, const Range& b) {
    if (a.start == b.start) {
        return a.end > b.end;
    }
    return a.start < b.start;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    // 1. Count how many ranges this range CONTAINS
    // Sweep Right-to-Left
    ordered_set<pair<int, int>> right_set;
    for (int i = n - 1; i >= 0; i--) {
        // We want to count elements with end <= current.end
        // {current.end + 1, -1} finds the boundary strictly greater than current.end
        contains[ranges[i].index] = right_set.order_of_key({ranges[i].end + 1, -1});
        
        // Insert the current range's end and index
        right_set.insert({ranges[i].end, ranges[i].index});
    }

    // 2. Count how many ranges this range is CONTAINED BY
    // Sweep Left-to-Right
    ordered_set<pair<int, int>> left_set;
    for (int i = 0; i < n; i++) {
        // We want to count elements with end >= current.end
        // order_of_key({current.end, -1}) returns count of elements strictly less than current.end.
        // We subtract this from the total size of the tree.
        int total_elements = left_set.size();
        int strictly_less = left_set.order_of_key({ranges[i].end, -1});
        
        contained[ranges[i].index] = total_elements - strictly_less;
        
        // Insert the current range's end and index
        left_set.insert({ranges[i].end, ranges[i].index});
    }

    // Output: Line 1 (contains)
    for (int i = 0; i < n; i++) {
        cout << contains[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    // Output: Line 2 (contained by)
    for (int i = 0; i < n; i++) {
        cout << contained[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}