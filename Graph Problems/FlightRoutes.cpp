#include <bits/stdc++.h>
using namespace std;

#define INF 9e15
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;


int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<vector<ll>> dist(n+1,vector<ll>(k,INF));
    dist[1][0] = 0;
    for (ll i = 1; i < k; ++i) {
        dist[1][i] = INF;
    }
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll node = pq.top().second;
        ll distance = pq.top().first;
        pq.pop();

        if(dist[node][k-1] < distance) continue;

        for(auto it : adj[node]){
            ll adjNode = it.first;
            ll wt = it.second;
            if(distance+wt < dist[adjNode][k-1]){
                dist[adjNode][k-1] = distance + wt;
                pq.push({dist[adjNode][k-1],adjNode});
                sort(dist[adjNode].begin(),dist[adjNode].end());
            }
        }
    }
    for(ll i=0;i<k;i++){
        cout<<dist[n][i]<<endl;
    }
    
    return 0;
}