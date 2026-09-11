#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

class SegmentTree{
    ll n;
    vector<ll> tree;
    public :
        SegmentTree(ll size){
            n = size;
            tree.resize(2*n,0);
        }
        void add(ll l, ll r, ll val){
            for(l+=n,r+=n;l<r;l>>=1,r>>=1){
                if(l&1) tree[l++] += val;
                if(r&1) tree[--r] += val;
            }
        }
        ll query(ll p){
            ll res = 0;
            for(p+=n;p>0;p>>=1){
                res += tree[p];
            }
            return res;
        }
};
ll timer = 0;
void dfs(vector<vector<ll>>&adj,vector<ll>&values,vector<ll>&in,vector<ll>&out, ll node, ll parent, SegmentTree&st, vector<ll>&pathSum){
    in[node] = timer++;
    st.add(in[node], in[node] + 1, pathSum[node]);
    for(auto adjNode: adj[node]){
        if(adjNode == parent) continue;
        pathSum[adjNode] = values[adjNode] + pathSum[node];
        dfs(adj,values,in,out,adjNode,node,st,pathSum);
    }
    out[node] = timer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    vector<ll> values(n);
    for(ll i=0;i<n;i++){
        cin>>values[i];
    }
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> in(n), out(n), pathSum(n,0);
    pathSum[0] = values[0];
    SegmentTree st(n); 
    dfs(adj,values,in,out,0,-1,st,pathSum);
    for(ll i=0;i<q;i++){
        ll type, s,x;
        cin>>type;
        if(type == 1){
            cin>>s>>x;
            s--;
            ll delta = x - values[s];
            st.add(in[s],out[s],delta);
            values[s] = x;
        }
        else{
            cin>>s;
            s--;
            cout<<st.query(in[s])<<"\n";
        }
    }   
    return 0;
}