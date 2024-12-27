#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;

void dfs1(ll node, vector<vector<ll>> &adj, vector<ll> &visited, stack<ll> &st) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs1(it, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(ll node, vector<vector<ll>> &adjRev, vector<ll> &visited, vector<ll> &scc) {
    visited[node] = 1;
    scc.push_back(node);
    for (auto it : adjRev[node]) {
        if (!visited[it]) {
            dfs2(it, adjRev, visited, scc);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> coins(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    vector<vector<ll>> adj(n + 1), adjRev(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }

    // Step 1: Topological Sort on Original Graph
    vector<ll> visited(n + 1, 0);
    stack<ll> st;

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Find SCCs using Transposed Graph
    fill(visited.begin(), visited.end(), 0);
    vector<ll> nodeToSCC(n + 1, 0);
    vector<ll> sccCoinSum;
    vector<vector<ll>> sccs;
    ll sccCount = 0;

    while (!st.empty()) {
        ll node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<ll> scc;
            dfs2(node, adjRev, visited, scc);
            sccs.push_back(scc);
            sccCount++;
            ll sum = 0;
            for (auto v : scc) {
                nodeToSCC[v] = sccCount;
                sum += coins[v];
            }
            sccCoinSum.push_back(sum);
        }
    }

    // Step 3: Build Condensed Graph
    vector<vector<ll>> dag(sccCount);
    for (ll u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            ll sccU = nodeToSCC[u] - 1;
            ll sccV = nodeToSCC[v] - 1;
            if (sccU != sccV) {
                dag[sccU].push_back(sccV);
            }
        }
    }

    // Step 4: Topological Sort on Condensed Graph
    vector<ll> topoOrder;
    fill(visited.begin(), visited.end(), 0);
    function<void(ll)> topoDFS = [&](ll node) {
        visited[node] = 1;
        for (auto it : dag[node]) {
            if (!visited[it]) {
                topoDFS(it);
            }
        }
        topoOrder.push_back(node);
    };

    for (ll i = 0; i < sccCount; i++) {
        if (!visited[i]) {
            topoDFS(i);
        }
    }
    reverse(topoOrder.begin(), topoOrder.end());

    // Step 5: DP on DAG to Find Max Coins
    vector<ll> dp(sccCount, 0);
    for (auto node : topoOrder) {
        dp[node] += sccCoinSum[node];
        for (auto neighbor : dag[node]) {
            dp[neighbor] = max(dp[neighbor], dp[node]);
        }
    }

    // Step 6: Output Maximum Coins
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
