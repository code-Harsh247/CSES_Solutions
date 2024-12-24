#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    int m =30;
    // Binary lifting table: mat[i][j] means 2^jth ancestor of node i
    vector<vector<int>> mat(m + 1, vector<int>(n+1, -1));

    // Base case: 2^0th ancestor is the direct parent
    for (int i = 1; i <= n; i++) {
        cin>>mat[0][i];
    }

    // Fill the table for 2^j jumps
    for (int i = 1; i <= m; i++) {  // Up to 2^30 steps
        for (int j = 1; j <= n; j++) {
            mat[i][j] = mat[i - 1][mat[i-1][j]];
        }
    }

    // Answer queries
    while (q--) {
        int x, k;
        cin >> x >> k;

        int result = x;
        for (int j = 0; j <= m; j++) {
            if (k & (1 << j)) {  // If the jth bit of k is set
                result = mat[j][result];
            }
        }
        cout << result << endl;
    }

    return 0;
}
