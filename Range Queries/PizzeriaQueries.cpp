#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

struct node{
    ll plus;
    ll minus;
    node(ll a, ll b) : plus(a), minus(b) {}
};

class SegmentTree{
    ll n;
    vector<node> tree;
    public:
        SegmentTree(ll size){
            n = size;
            tree.resize(4*n,{INF,INF});
        }
        void update(ll idx,ll val, ll i, ll l,ll r){
            if(l == r){
                tree[i].plus = val+idx;
                tree[i].minus = val-idx;
                return;
            }
            ll mid = l + (r-l)/2;
            if(idx <= mid){
                update(idx,val,2*i+1,l,mid);
            }
            else update(idx,val,2*i+2,mid+1,r);
            tree[i].plus = min(tree[2*i+1].plus, tree[2*i+2].plus);
            tree[i].minus = min(tree[2*i+1].minus, tree[2*i+2].minus);
        }
        node query(ll start,ll end,ll i, ll l,ll r){
            if(r<start || l>end) return {INF,INF};
            if(l>=start && r<=end) return tree[i];
            ll mid = l + (r-l)/2;
            node left = query(start,end,2*i+1,l,mid);
            node right = query(start,end,2*i+2,mid+1,r);
            node res = node(INF,INF);
            res.plus = min(left.plus, right.plus);
            res.minus = min(left.minus,right.minus);
            return res;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vector<ll> cost(n);
    SegmentTree st(n);
    for(ll i=0;i<n;i++){
        cin>>cost[i];
        st.update(i,cost[i],0,0,n-1);
    }
    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type == 1){
            ll k,x;
            cin>>k>>x;
            k--;
            st.update(k,x,0,0,n-1);
        }
        else{
            ll k;
            cin>>k;
            k--;
            node left = st.query(0,k,0,0,n-1);
            node right = st.query(k+1,n-1,0,0,n-1);
            cout<<min(left.minus+k, right.plus-k)<<"\n";
        }
    }


    return 0;
}