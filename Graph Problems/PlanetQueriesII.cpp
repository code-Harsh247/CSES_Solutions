#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int up[200000][20];

void dfs(vector<int>&arr, int node, vector<bool>&visited, vector<int>&len){
    if(visited[node]) return;
    visited[node] = true;
    dfs(arr, arr[node], visited,len);
    up[node][0] = arr[node];
    len[node] = len[up[node][0]]+1;
    for(int k=1;k<20;k++){
        up[node][k] = up[up[node][k-1]][k-1];
    }
}

int jump(int node, int dist){
    if(dist<0) return -1;
    for(int bit=0;bit<20;bit++){
        if((1<<bit)&dist){
            node = up[node][bit];
        }
    }
    return node;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<bool>visited(n+1,false);
    vector<int>len(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(arr,i,visited,len);
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int ans;
        int cycle_entry_a = jump(a,len[a]);
        if(jump(a,len[a]-len[b])==b){
            ans = len[a]-len[b];
        }
        else if(jump(cycle_entry_a,len[cycle_entry_a]-len[b])==b){
            ans = len[cycle_entry_a]-len[b]+len[a];
        }
        else ans = -1;
        cout<<ans<<"\n";
    }

    return 0;
}