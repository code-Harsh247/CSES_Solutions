#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MOD 1000000007

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // Base case for the first coin
    for (int t = 0; t <= x; t++)
    {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
        else
            dp[0][t] = INF;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= x; t++)
        {
            int notTake = dp[i - 1][t];
            int take = INF;
            if (t >= coins[i])
                take = 1 + dp[i][t - coins[i]];
            dp[i][t] = min(take, notTake);
        }
    }

    int ans = dp[n - 1][x];
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}
