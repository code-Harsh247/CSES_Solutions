#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;
ll timer = 0;

class SegmentTree{
    ll n;
    vector<ll> tree;
    public:
        SegmentTree(ll size){
            n = size;
            tree.resize(2*n,0);
        }

        void update(ll p, ll val){
            for(tree[p+=n]=val;p>1;p>>=1){
                tree[p>>1] = tree[p&~1] + tree[p|1];
            }
        }
        ll query(ll l, ll r){
            ll res = 0;
            for(l+=n,r+=n;l<r;l>>=1,r>>=1){
                if(l&1) res += tree[l++];
                if(r&1) res += tree[--r];
            }
            return res;
        }
};


void dfs(vector<vector<ll>>&adj, vector<ll>&values,vector<ll>&in, vector<ll>&out, ll node, ll parent, SegmentTree&st){
    in[node] = timer++;
    st.update(in[node],values[node]);
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        dfs(adj,values,in,out,adjNode,node,st);
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
    vector<vector<ll>>adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> in(n), out(n);
    SegmentTree st(n);
    dfs(adj,values,in,out,0,-1,st);
    for(ll i=0;i<q;i++){
        ll type,s,x;
        cin>>type;
        if(type == 1){
            cin>>s>>x;
            s--;
            st.update(in[s],x);
        }
        else{
            cin>>s;
            s--;
            cout<<st.query(in[s],out[s])<<endl;
        }
    }
    return 0;
}