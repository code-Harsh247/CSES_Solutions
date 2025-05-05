#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& list, vector<vector<ll>>& dp, ll i, ll j) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll pickLeft = list[i] + min(solve(list, dp, i + 2, j), solve(list, dp, i + 1, j - 1));
    ll pickRight = list[j] + min(solve(list, dp, i + 1, j - 1), solve(list, dp, i, j - 2));

    return dp[i][j] = max(pickLeft, pickRight);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> list(n);
    for (ll i = 0; i < n; i++) cin >> list[i];

    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << solve(list, dp, 0, n - 1) << endl;

    return 0;
}
