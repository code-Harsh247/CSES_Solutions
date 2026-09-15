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
    void build(ll i, ll l,ll r){
        if(l == r){
            tree[i] = 1;
            return;
        }
        ll mid = l + (r-l)/2;
        build(2*i+1,l,mid);
        build(2*i+2,mid+1,r);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

    public:
        SegmentTree(ll size): n(size){
            tree.resize(4*n);
            build(0,0,n-1);
        }
        ll query(ll k, ll i, ll l, ll r){
            if(l == r){
                tree[i] = 0;
                return l;
            }
            ll mid = l + (r-l)/2;
            ll res = 0;
            ll left = tree[2*i+1];
            if(left>=k){
                res = query(k,2*i+1,l,mid);
            }
            else res = query(k-left,2*i+2,mid+1,r);
            tree[i] = tree[2*i+1] + tree[2*i+2];
            return res;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }
    SegmentTree st(n);
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        ll idx = st.query(k,0,0,n-1);
        cout<<nums[idx]<<" ";
    }

    return 0;
}