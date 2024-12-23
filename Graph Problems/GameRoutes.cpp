#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int n, m;
    cin >> n >> m;


    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    //Topological Sort
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int adjNode : adj[i]) {
            indegree[adjNode]++;
        }
    }

    queue<int> q;
    vector<int> topo;
    vector<int> routes(n+1,0);
    routes[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int adjNode : adj[node]) {
            indegree[adjNode]--;
            routes[adjNode] = (routes[adjNode] + routes[node])%MOD;
            if (indegree[adjNode] == 0) {
                q.push(adjNode);
               
            }
        }
    }


    cout << routes[n] << endl;

    return 0;
}
