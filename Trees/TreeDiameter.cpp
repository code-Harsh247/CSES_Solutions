#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int diameter = 0;

void dfs(vector<vector<int>>&adj, vector<int>&dp, int node, int parent){
    int max1 = 0, max2 = 0;
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs(adj,dp,adjNode,node);
        int depth = dp[adjNode] + 1;

        if(depth > max1){
            max2 = max1;
            max1 = depth;
        }else if(depth > max2){
            max2 = depth;
        }

        diameter = max(diameter, max1+max2);
        dp[node] = max1;
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
    vector<int> dp(n+1);
    dfs(adj,dp,1,0);
    cout<<diameter<<endl;

    return 0;
}