#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void printDist(vector<ll> &dist){
	for(int i=1;i<dist.size();i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for (int i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<ll> dist(n + 1, 0);
    vector<ll> predecessors(n + 1, -1);

    int lastUpdated = -1;
    for (int i = 1; i <= n; i++) {
        lastUpdated = -1;
        for (auto it : edges) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                predecessors[v] = u;
                lastUpdated = v;
            }
        }
		// printDist(dist);
    }

    if (lastUpdated != -1) {
        cout << "YES" << endl;
        ll cycleStart = lastUpdated;

        // Ensure cycleStart is inside the cycle
        for (int i = 1; i <= n; i++) {
            cycleStart = predecessors[cycleStart];
        }

        vector<ll> cycle;
        for (ll curr = cycleStart;; curr = predecessors[curr]) {
            cycle.push_back(curr);
            if (curr == cycleStart && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());
		
        for (ll node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
