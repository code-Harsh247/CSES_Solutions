#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

void dfs(vector<multiset<int>> &adj, int node, vector<int> &path) {
    while (!adj[node].empty()) {
        int nextNode = *adj[node].begin();
        adj[node].erase(adj[node].begin());  //removing edges : node->nextNode
        adj[nextNode].erase(adj[nextNode].find(node)); // removing edge : nextNode -> node
        dfs(adj, nextNode, path);
    }       
    path.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    //using a multiset for the list of adjacent Nodes
    vector<multiset<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    // Check degree conditions
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // Hierholzer's Algorithm
    vector<int> path;
    dfs(adj, 1, path);

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(path.begin(), path.end());
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
