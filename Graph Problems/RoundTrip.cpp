#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
typedef vector<ll> vll;
 
vector<vector<int>> createAdj(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1);
    for (auto &edge : edges) {
        int from = edge.first;
        int to = edge.second;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    return adj;
}
 
bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node, int parent, vector<int> &path) {
    visited[node] = 1;
    path.push_back(node);
    for (auto it : adj[node]) {
        if (!visited[it]) {
            if (dfs(adj, visited, it, node, path)) {
                return true;
            }
        } else if (it != parent) {
            // Cycle detected
            path.push_back(it);
            return true;
        }
    }
    path.pop_back();
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<vector<int>> adj = createAdj(n, edges);
    vector<int> visited(n + 1, 0), path;
 
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(adj, visited, i, -1, path)) {
            // Cycle found, form the complete cycle
            int cycle_start = path.back();
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int j = path.size() - 2; j >= 0; j--) {
                cycle.push_back(path[j]);
                if (path[j] == cycle_start) break;
            }
            cout << cycle.size() << endl;
            for (auto node : cycle) {
                cout << node << " ";
            }
            cout << endl;
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
    return 0;
}