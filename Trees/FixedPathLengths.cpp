#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

// Moving to global scope prevents recursive stack-frame overhead
vector<int> adj[MAXN];
int subTreeSize[MAXN];
bool removed_node[MAXN];
int cnt[MAXN];
int max_depth;
long long total_paths = 0;
int n, k;

// Buffer to collect depths in a single DFS pass
vector<int> current_depths;

void getSubtreeSize(int node, int parent) {
    subTreeSize[node] = 1;
    for (int adjNode : adj[node]) {
        if (adjNode == parent || removed_node[adjNode]) continue;
        getSubtreeSize(adjNode, node);
        subTreeSize[node] += subTreeSize[adjNode];  
    }
}

int getCentroid(int node, int parent, int size) {
    for (int adjNode : adj[node]) {
        if (adjNode != parent && !removed_node[adjNode] && subTreeSize[adjNode] > size / 2) {
            return getCentroid(adjNode, node, size);
        }
    }
    return node;
}

// OPTIMIZATION: Collect depths instead of running 2 separate DFS functions
void get_depths(int node, int parent, int depth) {
    if (depth > k) return;
    max_depth = max(max_depth, depth);
    current_depths.push_back(depth);
    
    for (int adjNode : adj[node]) {
        if (adjNode == parent || removed_node[adjNode]) continue;
        get_depths(adjNode, node, depth + 1);
    }
}

void decompose(int node, int parent) {
    getSubtreeSize(node, parent);
    int centroid = getCentroid(node, parent, subTreeSize[node]);
    
    cnt[0] = 1; 
    max_depth = 0;
    
    for (int adjNode : adj[centroid]) {
        if (removed_node[adjNode]) continue;
        
        current_depths.clear();
        get_depths(adjNode, centroid, 1);
        
        // Count paths using the collected depths
        for (int d : current_depths) {
            total_paths += cnt[k - d];
        }
        // Then populate the count array
        for (int d : current_depths) {
            cnt[d]++;
        }
    }
    
    // Quick reset based on max_depth seen in this component
    fill(cnt + 1, cnt + max_depth + 1, 0);
    
    removed_node[centroid] = true;
    for (int adjNode : adj[centroid]) {
        if (removed_node[adjNode]) continue;
        decompose(adjNode, centroid);
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k)) return 0;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Prevent vector dynamic reallocation overhead
    current_depths.reserve(n);
    
    decompose(1, 0);
    
    cout << total_paths << "\n";
    return 0;
}