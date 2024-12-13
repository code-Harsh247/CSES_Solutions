#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

vector<vector<pair<ll, ll>>> createAdj(ll n, vector<vector<ll>> &edges) {
    vector<vector<pair<ll, ll>>> adj(n + 1);  // 1-indexed adjacency list
    for (auto &edge : edges) {
        ll from = edge[0];
        ll to = edge[1];
        ll length = edge[2];
        adj[from].push_back({to, length});
    }
    return adj;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> flights;
    for (ll i = 0; i < m; i++) {
        ll from, to, length;
        cin >> from >> to >> length;
        flights.push_back({from, to, length});
    }

    // Create adjacency list
    vector<vector<pair<ll, ll>>> adj = createAdj(n, flights);

    // Dijkstra's algorithm
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distances(n + 1, LLONG_MAX);  // Initialize distances to LLONG_MAX
    distances[1] = 0;  // Distance to source node is 0
    pq.push({0, 1});   // Push source node

    while (!pq.empty()) {
        ll dist = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if (dist > distances[node]) continue;  // Ignore stale entries

        for (auto it : adj[node]) {
            ll adjNode = it.first;
            ll edW = it.second;

            if (dist + edW < distances[adjNode]) {
                distances[adjNode] = dist + edW;
                pq.push({distances[adjNode], adjNode});
            }
        }
    }

    // Output distances
    for (ll i = 1; i <= n; i++) {
        if (distances[i] == LLONG_MAX) cout << "INF ";
        else cout << distances[i] << " ";
    }

    return 0;
}
    