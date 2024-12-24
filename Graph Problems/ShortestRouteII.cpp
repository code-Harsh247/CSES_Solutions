#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX

#define ll long long

// Floyd Warshall Algorithm
void shortest_distance(vector<vector<ll>> &matrix, ll n) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = INF; 
            }
            if (i == j) {
                matrix[i][j] = 0; // Distance to self is 0
            }
        }
    }

    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (matrix[i][k] < INF && matrix[k][j] < INF) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (matrix[i][j] == INF) {
                matrix[i][j] = -1; // Reset unreachable paths to -1
            }
        }
    }
}

int main() {
    ll n, m, q;
    cin >> n >> m >> q; 

    vector<vector<ll>> adjMat(n + 1, vector<ll>(n + 1, -1)); // 

    for (ll i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        if (adjMat[u][v] == -1 || adjMat[u][v] > wt) {
            adjMat[u][v] = wt;
            adjMat[v][u] = wt; // Keep the smallest weight
        }
    }

    
    shortest_distance(adjMat, n);

    while (q--) {
        ll a, b;
        cin >> a >> b; 
        cout << adjMat[a][b] << endl; 
    }

    return 0;
}
