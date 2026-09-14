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
        tree.resize(2*n,1e18);
    }
    void update(ll p, ll val){
        for(tree[p+=n]=val;p>1;p>>=1){
            tree[p>>1] = min(tree[p&~1],tree[p|1]);
        }
    }
    ll query(ll l, ll r){
        ll res = 1e18;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1) res = min(tree[l++], res);
            if(r&1) res = min(tree[--r], res);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    SegmentTree st(n);
    for(ll i=0;i<n;i++){
        ll num;
        cin>>num;
        st.update(i,num);
    }
    for(ll i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<st.query(l,r)<<endl;
    }

    return 0;
}