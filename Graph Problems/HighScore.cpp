#include <bits/stdc++.h>
using namespace std;

#define INF 1e17
#define MOD 1000000007
#define NINF (-1)*INF 

typedef long long ll;

typedef vector<ll> vll;

//Using Bellmon Ford
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges; 
    for(ll i=0;i<m;i++){
        ll a,b,wt;
        cin>>a>>b>>wt;
        edges.push_back({a,b,-1*wt});
    }
    vector<ll> dist(n+1,LLONG_MAX);
    dist[1] = 0;
    for(ll i=1;i<=n;i++){
        for(auto it : edges){
            ll u,v,wt;
            u = it[0];
            v = it[1];
            wt = it[2];
            if(dist[u] != LLONG_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u]+wt; 
            }
        }
    }

    //if there are negative cycles, then NINF will be propagated. And if any node belonging to a path between node 1 and node n is part of a cycle, then NINF will eventually propagate to node n. 

    for(ll i=1;i<=n;i++){
        for(auto it : edges){
            ll u,v,wt;
            u = it[0];
            v = it[1];
            wt = it[2];
            if(dist[u] != LLONG_MAX && dist[u] + wt < dist[v]){
                dist[v] = NINF; 
            }
        }
    }

    if(dist[n] != NINF) cout<<-1*dist[n]<<endl;
    else cout<<-1<<endl;



    return 0;
}