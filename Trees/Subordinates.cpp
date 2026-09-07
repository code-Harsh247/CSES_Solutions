#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int dfs(vector<vector<int>>&adj, int node, vector<int>&subs){
    if(adj[node].size() == 0) return 0;
    int subCount = 0;
    for(int adjNode : adj[node]){
        subCount += 1 + dfs(adj,adjNode,subs);
    }
    subs[node] = subCount;
    return subCount;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    vector<int> subs(n+1);
    int dummy = dfs(adj,1,subs);
    for(int i=1;i<=n;i++){
        cout<<subs[i]<<" ";
    }

    return 0;
}