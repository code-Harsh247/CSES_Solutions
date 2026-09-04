#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

ll solve(vector<vector<ll>>&adjMat, ll n, ll u, ll mask, vector<vector<ll>>&memo){
    if(u==n-1){
        if(mask==(1<<n)-1) return 1;
        else return 0;
    }
    if(memo[mask][u]!=-1) return memo[mask][u];
    ll res = 0;
    for(ll v=0;v<n;v++){
        if(adjMat[u][v]>0 && !(mask&(1<<v))){
            ll paths = (adjMat[u][v]*solve(adjMat,n,v,mask|(1<<v),memo));
            res = (res+paths)%MOD;
        }
    }
    return memo[mask][u] = res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adjMat(n, vector<ll>(n,0));
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        adjMat[u][v]++;
    }
    vector<vector<ll>> memo(1<<n,vector<ll>(n,-1));    
    ll result = solve(adjMat,n,0,1,memo);
    cout<<result<<endl;
    return 0;
}