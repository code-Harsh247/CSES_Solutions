#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;

int main() {
    int n;
    cin >> n;
    vll songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    set<ll> s; // To track unique elements in the current window
    int maxStreak = 0;
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; right < n; right++) {
        while (s.find(songs[right]) != s.end()) {
            // Remove elements from the left until songs[right] becomes unique
            s.erase(songs[left]);
            left++;
        }
        s.insert(songs[right]);
        maxStreak = max(maxStreak, right - left + 1);
    }

    cout << maxStreak << endl;
    return 0;
}
