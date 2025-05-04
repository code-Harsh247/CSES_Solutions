#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int budget = 0; budget <= x; budget++) {
            int notTake = dp[i - 1][budget];
            int take = 0;
            if (budget >= prices[i - 1]) {
                take = pages[i - 1] + dp[i - 1][budget - prices[i - 1]];
            }
            dp[i][budget] = max(take, notTake);
        }
    }

    cout << dp[n][x] << endl;
    return 0;
}
