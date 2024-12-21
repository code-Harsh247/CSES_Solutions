#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> topo;
    vector<int> visited(n+1,-1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        visited[node] = 1;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    bool solExist = true;
    for(int i=1;i<=n;i++){
        if(visited[i]==-1) solExist= false; 
    }
    if(!solExist) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(auto it : topo){
        cout<<it<<" ";
        }
    }

    return 0;
}