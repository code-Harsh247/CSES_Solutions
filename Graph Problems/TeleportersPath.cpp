#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void dfs(vector<set<int>> &adj, int node, vector<int> &path){
    // cout<<node<<endl;
    while(!adj[node].empty()){
        auto itr_nextNode = adj[node].begin();
        int nextNode = *itr_nextNode;
        adj[node].erase(itr_nextNode);

        dfs(adj,nextNode, path);
    }
    path.push_back(node);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
    }
    vector<int> outdegrees(n+1,0);
    vector<int> indegrees(n+1,0);
    //check if a euler path is possible
    for(int i=1;i<=n;i++){
        outdegrees[i] = adj[i].size();
        for(auto it : adj[i]){
            int node = it;
            indegrees[node]++;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<indegrees[i]<<" "<<outdegrees[i]<<endl;
    // }
    if(outdegrees[1]-indegrees[1] ==1 && indegrees[n] - outdegrees[n] == 1){
        for(int i=2;i<=n-1;i++){
            if(indegrees[i] != outdegrees[i]){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    // cout<<"POSSIBLE"<<endl;
    vector<int> path;
    dfs(adj,1,path);
    reverse(path.begin(),path.end());

    if(path.size()!=m+1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto it : path){
        cout<<it<<" ";
    }


    return 0;
}