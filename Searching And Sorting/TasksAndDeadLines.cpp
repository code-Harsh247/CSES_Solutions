#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> tasks;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        tasks.push_back({a, b});
    }

    sort(tasks.begin(), tasks.end());

    ll time =0,polls = 0;
    for(auto it : tasks){
        polls += it.second - it.first - time;
        time += it.first;
    }
    cout<<polls<<endl;

    return 0;
}
