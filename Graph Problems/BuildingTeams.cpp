#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

vector<vector<int>> createAdj(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1);
    for (auto &edge : edges) {
        int from = edge.first;
        int to = edge.second;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    return adj;
}

bool dfs(vector<vector<int>> &adj, int col, int node, vector<int> &colors){
    colors[node] = col;
    int oppCol = col==1? 2:1;
    for(auto it: adj[node]){
        if(colors[it] == -1){
            if(!dfs(adj, oppCol, it, colors)) return false;
        }
        else if(colors[it] == col){
            return false;
        }
    }
    return true;
}


//JUST CHECK FOR BIPARTITE GRAPH

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<vector<int>> adj = createAdj(n,edges);
    vector<int> colors(n+1,-1);
    bool ans = true;
    for(int i=0;i<n;i++){
        if(colors[i] == -1){
            if(!dfs(adj,1,i,colors)) ans = false;
        }
    }
    if(ans) {
        for(int i=1;i<colors.size();i++){
            cout<<colors[i]<<" ";
        }
    } 
    else cout<<"IMPOSSIBLE"<<endl;

    
    return 0;
}