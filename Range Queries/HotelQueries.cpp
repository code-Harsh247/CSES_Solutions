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
    vector<pii>tree;
    void update(ll idx, ll val, ll i, ll l, ll r){
        if(l == r){
            tree[i] = {val,idx+1};
            return;
        }
        ll mid = l + (r-l)/2;
        if(idx <= mid){
            update(idx,val,2*i+1,l,mid);
        }
        else update(idx,val,2*i+2,mid+1,r);
        if(tree[2*i+1].first >= tree[2*i+2].first){
            tree[i] = tree[2*i+1];
        }
        else tree[i] = tree[2*i+2];
    }

    ll query(ll val,ll i, ll l, ll r){
        if(tree[i].first < val) return 0;
        if(l == r){
            tree[i] = {tree[i].first - val,tree[i].second};
            return tree[i].second;
        }
        ll mid = l + (r-l)/2;
        ll res;
        pii leftChild = tree[2*i+1];
        pii rightChild = tree[2*i+2];
        if(leftChild.first < val && rightChild.first < val) return 0;
        else if(leftChild.first >= val){
            res = query(val,2*i+1,l,mid);
        }
        else res = query(val,2*i+2,mid+1,r);
        if(tree[2*i+1].first >= tree[2*i+2].first){
            tree[i] = tree[2*i+1];
        }
        else tree[i] = tree[2*i+2];
        return res;
    }

    public:
        SegmentTree(ll size){
            n = size;
            tree.resize(4*n,{-1,-1});
        }
        void updateTree(ll idx, ll val){
            update(idx,val,0,0,n-1);
        }
        ll queryTree(ll val){
            return query(val,0,0,n-1);
        }
        
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    SegmentTree st(n);
    vector<ll> hotels(n);
    for(ll i=0;i<n;i++){
        cin>>hotels[i];
        st.updateTree(i,hotels[i]);
    }
    for(ll i=0;i<m;i++){
        ll req;
        cin>>req;
        cout<<st.queryTree(req)<<"\n";
    }

    return 0;
}