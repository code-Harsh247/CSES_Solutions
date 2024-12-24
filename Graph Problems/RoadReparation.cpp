#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;


//MST
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    } 
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    ll sum = 0;
    vector<ll> visited(n+1,0);
    while(!pq.empty()){
        ll node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        if(visited[node]) continue;

        visited[node] = 1;
        sum+=cost;
        for(auto it : adj[node]){
            ll adjNode = it.first;
            ll wt = it.second;
            if(!visited[adjNode]){
                pq.push({wt,adjNode});
                
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(visited[i] == 0){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<sum<<endl;
    return 0;
}