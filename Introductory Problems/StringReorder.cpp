#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int cnt[26] = {};
    for (char ch : s) cnt[ch - 'A']++;

    for (int i = 0; i < 26; i++) {
        if (2 * cnt[i] > n + 1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    string res;
    res.reserve(n);
    int prev = -1;

    for (int m = n; m > 0; m--) {        
        int pick = -1;
        for (int i = 0; i < 26; i++) {
            if (2 * cnt[i] > m) { pick = i; break; }
        }

        if (pick == -1) {
            for (int i = 0; i < 26; i++) {
                if (i != prev && cnt[i] > 0) { pick = i; break; }
            }
        }

        res += char('A' + pick);
        cnt[pick]--;
        prev = pick;
    }

    cout << res << '\n';
    return 0;
}