#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void bfs(vector<vector<int>> adj, int src, vector<int> &visited){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                q.push(it);
            }
        }
    }
}


//do a bfs from node 1 and check if we reach all nodes. Then do a bfs from node 1 in a reversed graph to check if we reach 1 from all nodes
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1); 
    vector<vector<int>> adjRev(n+1); 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjRev[v].push_back(u);
    }
    vector<int> visited(n+1,0);
    bfs(adj,1,visited);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    visited = vector<int>(n+1,0);
    bfs(adjRev,1,visited);
        for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    
    return 0;
}