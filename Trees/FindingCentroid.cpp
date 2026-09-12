#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
int res;

void dfs(vector<vector<int>>&adj,vector<int>&subtreeSize, int node,int parent){
    subtreeSize[node] = 1;
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs(adj,subtreeSize,adjNode,node);
        subtreeSize[node] += subtreeSize[adjNode];
    }
}

void dfs2(vector<vector<int>>&adj,vector<int>&subtreeSize,int node, int parent, int n){
    for(auto adjNode : adj[node]){
        if(adjNode != parent && subtreeSize[adjNode] > n/2){
            return dfs2(adj,subtreeSize,adjNode,node,n);
        }
    }
    res = node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> subtreeSize(n+1);
    dfs(adj,subtreeSize,1,0);
    dfs2(adj,subtreeSize,1,0,n);
    cout<<res;
    return 0;
}