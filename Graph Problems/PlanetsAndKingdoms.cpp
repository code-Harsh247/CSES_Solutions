#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
 
typedef vector<ll> vll;
 
void dfs(vector<vector<int>> &adj, int node, vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(adj,it,visited,st);
        }
    }
    st.push(node);
}
 
void dfs2(vector<vector<int>> &adj, int node, vector<int> &visited, int kingdom){
    visited[node] = kingdom;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs2(adj,it,visited,kingdom);
        }
    }
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> adjRev(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }
    vector<int> visited(n+1,0);
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,i,visited,st);
        }
    }
    visited = vector<int>(n+1,0);
    vector<int> kingdoms(n+1,0);
    int kingdomNumber = 1;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!kingdoms[node]){
            dfs2(adjRev,node,kingdoms,kingdomNumber++);
        }
    }
    cout<<kingdomNumber-1<<endl;
    for(int it = 1;it<=n;it++){
        cout<<kingdoms[it]<<" ";
    }
 
 
    return 0;