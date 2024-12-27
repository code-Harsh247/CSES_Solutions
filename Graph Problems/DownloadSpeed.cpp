#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

#define ll long long

class Dinic {
public:
    struct Edge {
        ll to, rev;  // Destination node and reverse edge index
        ll flow, capacity;
    };

    vector<vector<Edge>> flowGraph;
    vector<ll> level;
    vector<ll> ptr;  // Poller for DFS
    ll N, src, sink;

    Dinic(ll n, ll s, ll t) {
        N = n;
        src = s;
        sink = t;
        flowGraph.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }

    void addEdge(ll from, ll to, ll capacity) {
        Edge forward = {to, (ll)flowGraph[to].size(), 0, capacity};
        Edge backward = {from, (ll)flowGraph[from].size(), 0, 0};
        flowGraph[from].push_back(forward);
        flowGraph[to].push_back(backward);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<ll> q;
        q.push(src);
        level[src] = 0;

        while (!q.empty()) {
            ll node = q.front();
            q.pop();

            for (auto &e : flowGraph[node]) {
                if (e.flow < e.capacity && level[e.to] == -1) {
                    level[e.to] = level[node] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;  // Return true if sink is reachable
    }

    ll dfs(ll node, ll pushed) {
        if (pushed == 0) return 0;  // No flow to push
        if (node == sink) return pushed;  // Reached sink, push flow

        for (ll &cid = ptr[node]; cid < (ll)flowGraph[node].size(); ++cid) {
            Edge &e = flowGraph[node][cid];
            if (e.flow < e.capacity && level[e.to] == level[node] + 1) {
                ll minFlow = min(pushed, e.capacity - e.flow);
                ll flow = dfs(e.to, minFlow);
                if (flow > 0) {
                    e.flow += flow;
                    flowGraph[e.to][e.rev].flow -= flow;
                    return flow;
                }
            }
        }
        return 0;  // No flow could be pushed
    }

    ll maxFlow() {
        ll totalFlow = 0;

        while (bfs()) {  // Construct level graph
            fill(ptr.begin(), ptr.end(), 0);
            while (ll flow = dfs(src, INF)) {
                totalFlow += flow;
            }
        }
        return totalFlow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    ll src = 1, sink = n;  // Assuming source is 1 and sink is n
    Dinic dinic(n, src, sink);

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dinic.addEdge(a, b, c);
    }

    cout <<dinic.maxFlow() << endl;

    return 0;
}
