#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

void dfs1(vector<vector<ll>>&adj,vector<ll>&nodesBelow, ll node, ll parent){
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs1(adj,nodesBelow,adjNode,node);
        nodesBelow[node] += 1+nodesBelow[adjNode];
    }
}

void dfs2(vector<vector<ll>>&adj, vector<ll>&nodesBelow, vector<ll>&in, ll node, ll parent){
    in[node] = nodesBelow[node];
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs2(adj,nodesBelow,in,adjNode,node);
        in[node] += in[adjNode];
    }
}


// The distance from 'node' to all nodes EXCEPT adjNode's subtree is:
// out[node] + in[node] - (in[adjNode] + nodesBelow[adjNode] + 1)
// Stepping down to adjNode adds 1 distance to all those outside nodes.
// How many outside nodes? n - (nodesBelow[adjNode] + 1)

void dfs3(vector<vector<ll>>&adj,ll n,vector<ll>&in,vector<ll>&out, vector<ll>&nodesBelow,ll node, ll parent){
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        out[adjNode] = out[node] + in[node] - in[adjNode] - 2 * nodesBelow[adjNode] + n - 2;
        dfs3(adj,n,in,out,nodesBelow,adjNode,node);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> in(n+1),nodesBelow(n+1),out(n+1);
    dfs1(adj,nodesBelow,1,0);
    dfs2(adj,nodesBelow,in,1,0);
    dfs3(adj,n,in,out,nodesBelow,1,0);
    for(ll i=1;i<=n;i++){
        cout<<in[i]+out[i]<<" ";
    }
    return 0;
}