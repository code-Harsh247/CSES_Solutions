#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

int main()
{
    int max_n = 1e6 + 10;  // You can adjust based on constraints
    vector<vector<ll>> dp(max_n, vector<ll>(8, 0));
    
    for (int i = 0; i < 8; i++)
        dp[0][i] = 1;
    
    for (int i = 1; i < max_n; i++)
    {
        for (int j = 0; j < 8; j++)
        {   
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5)
            {
                dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] +
                            dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % MOD;
            }
            else
            {
                dp[i][j] = (dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][7]) % MOD;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        cout << (dp[len - 1][2] + dp[len - 1][6]) % MOD << endl;
    }

    return 0;
}
