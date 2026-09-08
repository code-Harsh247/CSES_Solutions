#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

void dfs(vector<vector<int>>&adj, vector<vector<int>>&dp, int node, int parent){
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;

        dfs(adj,dp,adjNode,node);

        dp[node][0] += max(dp[adjNode][1],dp[adjNode][0]);
    }
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        int take = dp[node][0] - max(dp[adjNode][1],dp[adjNode][0]) + 1 + dp[adjNode][0];
        dp[node][1] = max(take,dp[node][1]);
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
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dfs(adj,dp,1,0);
    cout<<max(dp[1][1],dp[1][0])<<endl;
    return 0;
}