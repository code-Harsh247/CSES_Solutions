#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    // Create adjacency list
    vector<vector<int>> adj = createAdj(n, edges);

    // BFS setup
    queue<int> q;
    vector<int> distances(n + 1, 1e9);  // Distance to each node
    vector<int> parents(n+1);
    parents[1] = 1;
    distances[1] = 1;
    q.push(1);

    // BFS traversal
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distances[neighbor] == 1e9) {  // Unvisited node
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
                parents[neighbor] = node;
            }
        }
    }

    // Output result
    if (distances[n] != 1e9){
        cout << distances[n] << endl;
        int current = n;
        vector<int> path;
        while(current!=parents[current]){
            path.push_back(current);
            current = parents[current];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(auto it: path){
            cout<<it<<" ";
        }
    }
        
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
