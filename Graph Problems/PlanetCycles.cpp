#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int cycleLen = 0;
int cycleStart = -1;

void dfs(vector<int>&arr, int u, int dist,vector<bool>&visited, vector<int>&distance, vector<int>&dp){
    if(visited[u]) return;
    visited[u] = true;
    int v = arr[u];
    distance[u] = dist;
    if(!visited[v]){
        dfs(arr,v,dist+1,visited,distance,dp);
    }else{
        if(dp[v]==0){
            cycleStart = v;
            cycleLen = distance[u]-distance[v]+1;
        }
        else cycleLen = dp[v];
    }

    if(cycleStart!=-1){
        dp[u] = cycleLen;
        if(u == cycleStart){
            cycleStart = -1;
        }
    }else{
        dp[u] = dp[v]+1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1,0), distance(n+1,0);
    vector<bool> visited(n+1,false);
    int cycleStart = -1, cycleLen = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cycleStart = -1;
            cycleLen = 0;
            dfs(arr,i,1,visited,distance,dp);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}