#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

void dfs1(vector<vector<int>>&adj, vector<int>&in, vector<int>&in2,vector<int>&longestPathNode, int node, int parent){

    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs1(adj,in,in2,longestPathNode,adjNode,node);
        int currPath = 1 + in[adjNode];
        if(currPath > in[node]){
            in2[node] = in[node]; 
            in[node] = currPath;
            longestPathNode[node] = adjNode;
        }else if(currPath > in2[node]){
            in2[node] = currPath;
        }
    }
}

void dfs2(vector<vector<int>>&adj, vector<int>&out, vector<int>&in, vector<int>&in2,vector<int>&longestPathNode, int node, int parent){
    int maxDist = 0;
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        if(longestPathNode[node] == adjNode){
            maxDist = in2[node];
        }else{
            maxDist = in[node];
        }
        out[adjNode] = 1 + max(out[node],maxDist);
        dfs2(adj,out,in,in2,longestPathNode,adjNode,node);        
    }
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
    vector<int> in(n+1), in2(n+1),out(n+1),longestPathNode(n+1);
    dfs1(adj,in,in2,longestPathNode,1,0);
    dfs2(adj,out,in,in2,longestPathNode,1,0);
    for(int i=1;i<=n;i++){
        cout<<max(in[i],out[i])<<" ";
    }
    return 0;
}