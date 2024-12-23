#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll,ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }

    vector<ll> distances(n+1,INF);
    distances[1] = 0;
    vector<ll> ways(n+1,0);
    ways[1] = 1;
    vector<ll> maxWays(n+1,0), minWays(n+1,INF);
    maxWays[1] = 0;
    minWays[1] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll node = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();

        if (dist > distances[node]) continue;

        for(auto it : adj[node]){
            ll adjNode = it.first;
            ll wt = it.second;
            if(dist+wt < distances[adjNode]){
                distances[adjNode] = dist + wt;
                pq.push({dist+wt,adjNode});
                ways[adjNode] = ways[node];
                maxWays[adjNode] = maxWays[node] + 1;
                minWays[adjNode] = minWays[node] + 1;
            }

            else if(dist+wt == distances[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node])%MOD;
                maxWays[adjNode] = max(maxWays[adjNode], maxWays[node] + 1);
                minWays[adjNode] = min(minWays[adjNode], minWays[node] + 1);
            }
        }
    }

    cout<<distances[n]<<" "<<ways[n]<<" "<<minWays[n]<<" "<<maxWays[n]<<endl;
    return 0;
}