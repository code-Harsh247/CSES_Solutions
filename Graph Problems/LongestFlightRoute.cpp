#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

vector<int> getTopoOrder(vector<vector<int>> &adj, int n) {
    vector<int> topo;
    vector<int> indegree(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int adjNode : adj[i]) {
            indegree[adjNode]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int adjNode : adj[node]) {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    return topo;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    vector<int> topo = getTopoOrder(adj, n);


    vector<int> distance(n + 1, -INF);
    vector<int> predecessor(n + 1, -1);
    distance[1] = 0;

    for (int node : topo) {
        if (distance[node] == -INF) continue; // Skip unreachable nodes

        for (int adjNode : adj[node]) {
            if (distance[node] + 1 > distance[adjNode]) {
                distance[adjNode] = distance[node] + 1;
                predecessor[adjNode] = node;
            }
        }
    }


    if (distance[n] == -INF) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    for (int node = n; node != -1; node = predecessor[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    cout<<path.size()<<endl;
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
