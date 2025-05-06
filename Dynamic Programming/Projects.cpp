#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> projects(n, vector<ll>(3));
    for (ll i = 0; i < n; ++i) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    // Sort projects by end time
    sort(projects.begin(), projects.end(), [](auto &a, auto &b){
        return a[1] < b[1];
    });

    vector<ll> dp(n);
    vector<ll> endTimes(n);
    for (ll i = 0; i < n; ++i) endTimes[i] = projects[i][1];

    for (ll i = 0; i < n; ++i) {
        ll includeProfit = projects[i][2];
        // Binary search for the last project that doesn't overlap
        ll l = 0, r = i - 1, pos = -1;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (projects[m][1] < projects[i][0]) {
                pos = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (pos != -1) includeProfit += dp[pos];
        dp[i] = max((i > 0 ? dp[i - 1] : 0), includeProfit);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
