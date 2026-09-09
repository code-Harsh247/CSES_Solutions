#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int up[200005][20];
int depth[200005];

void dfs(vector<vector<int>>&adj, int node , int parent){
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        up[adjNode][0] = node;
        depth[adjNode] = 1 + depth[node];
        dfs(adj,adjNode,node);
    }
}

int getLCA(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int depthDiff = depth[u] - depth[v];
    for(int k=0;k<20;k++){
        if(depthDiff&(1<<k)){
            u = up[u][k];
        }
    }
    if(u == v) return u;
    for(int k=19;k>=0;k--){
        if(up[u][k] != up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}
void dfs2(vector<vector<int>>&adj, int node, int parent, vector<int>&path){
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs2(adj,adjNode,node,path);
        path[node] += path[adjNode];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> path(n);
    memset(up,-1,sizeof(up));
    memset(depth,0,sizeof(depth));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,0,-1);
    for(int k=1;k<20;k++){
        for(int node=0;node<n;node++){
            if(up[node][k-1]!=-1) up[node][k] = up[up[node][k-1]][k-1]; 
        }
    }
    for(int i=0;i<m;i++){
        int start,end;
        cin>>start>>end;
        start--;
        end--;
        int lca = getLCA(start,end);
        int lca_parent = up[lca][0];
        path[start] += 1;
        path[end] += 1;
        path[lca] -= 1;
        if(lca_parent!=-1) path[lca_parent] -= 1;
    }
    dfs2(adj,0,-1,path);
    for(int i=0;i<n;i++){
        cout<<path[i]<<" ";
    }
    return 0;
}