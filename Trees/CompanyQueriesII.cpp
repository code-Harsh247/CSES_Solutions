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

void dfs(vector<vector<int>>&adj, int node, int parent){
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        depth[adjNode] = 1 + depth[node];
        dfs(adj,adjNode,node);
    }
}

int findLCA(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int depthDiff = depth[u] - depth[v];
    for(int i=0;i<20;i++){
        if(depthDiff & (1<<i)){
            u = up[u][i];
        }
    }
    if(u == v) return u;
    for(int k=19;k>=0;k--){
        if(up[u][k] != -1 && up[u][k] !=-1){
            if(up[u][k] != up[v][k]){
                u = up[u][k];
                v = up[v][k];
            }
        }
    }
    return up[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n);
    memset(up,-1,sizeof(up));
    for(int i=1;i<n;i++){
        int e;
        cin>>e;
        e--;
        up[i][0] = e;
        adj[e].push_back(i);
        adj[i].push_back(e);
    }
    dfs(adj,0,-1);
    for(int k=1;k<20;k++){
        for(int node=0;node<n;node++){
            if(up[node][k-1] != -1) up[node][k] = up[up[node][k-1]][k-1];
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        cout<<findLCA(a,b)+1<<endl;
    }
    return 0;
}