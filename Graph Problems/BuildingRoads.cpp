#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

class DisjointSet{
    public:
        vector<int> rank, parents;
        DisjointSet(int n) {
            rank.resize(n+1,0);
            parents.resize(n+1);
            for(int i=0;i<=n;i++){
                parents[i] = i;
            }
        }

        int getParent(int node){
            if(node == parents[node]) return node;
            else return parents[node] = getParent(parents[node]);
        }

        void unionByRank(int u, int v){
            int pu = getParent(u);
            int pv = getParent(v);
            if(rank[pu] < rank[pv]) parents[pu] = pv;
            if(rank[pv] < rank[pu]) parents[pv] = pu;
            else {
                parents[pu] = pv;
                rank[pv]++;
            }
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    DisjointSet s(n);
    for(auto it : edges){
        int u = it.first;
        int v = it.second;
        if(s.getParent(u) != s.getParent(v)){
            s.unionByRank(u,v);
        }
    }
    int components = 0;
    vector<int> cities;
    for(int i=1;i<=n;i++){
        
        if(s.getParent(i) == i){
            cities.push_back(i);
            components++;
        }
        
    }
    
    cout<<components-1<<endl;
    for(int i=1;i<cities.size();i++){
        cout<<cities[i]<<" "<<cities[i-1]<<endl;
    }

    return 0;
}