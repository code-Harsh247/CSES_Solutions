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

    ll query(ll start, ll end, ll i, ll l, ll r){
        if(start<=l && r<=end){
            return tree[i];
        }
        else if(r<start || end<l){
            return 0;
        }
        ll mid = l+(r-l)/2;
        return query(start,end,2*i+1,l,mid) + query(start,end,2*i+2,mid+1,r);
    }
    void update(ll idx, ll i,ll l, ll r, ll delta){
        if(l == r){
            tree[i] += delta;
            return;
        }
        ll mid = l + (r-l)/2;
        if(idx <= mid){
            update(idx,2*i+1,l,mid,delta);
        }
        else update(idx,2*i+2,mid+1,r,delta);
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }
    public:
        SegmentTree(ll size): n(size)
        {
            tree.resize(4*n,0);
        }
        void updateTree(ll idx,ll delta){
            update(idx, 0, 0, n-1,delta);
        }
        ll queryTree(ll a,ll b){
            return query(a,b,0,0,n-1);
        }
};

struct Query {
    char type;
    ll a, b;
};

int getCompressed(ll x, vector<ll>&vals){
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    vector<ll> salary(n), vals;
    for(ll i=0;i<n;i++){ 
        cin>>salary[i];
        vals.push_back(salary[i]);
    }
    vector<Query> queries(q);
    for (ll i = 0; i < q; i++) {
        cin >> queries[i].type >> queries[i].a >> queries[i].b;
        if (queries[i].type == '!') {
            vals.push_back(queries[i].b);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    SegmentTree st(vals.size());

    for (ll i = 0; i < n; i++) {
        st.updateTree(getCompressed(salary[i], vals), 1);
    }

    for (ll i = 0; i < q; i++) {
        if (queries[i].type == '!') {
            ll emp_idx = queries[i].a - 1; // 0-based index
            ll old_salary = salary[emp_idx];
            ll new_salary = queries[i].b;
            
            // Remove old salary from tree
            st.updateTree(getCompressed(old_salary,vals), -1);
            
            // Update array and add new salary to tree
            salary[emp_idx] = new_salary;
            st.updateTree(getCompressed(new_salary,vals), 1);
        } 
        else {
            ll start_val = queries[i].a;
            ll end_val = queries[i].b;
            
            // Find compressed boundaries for the range
            ll comp_A = lower_bound(vals.begin(), vals.end(), start_val) - vals.begin();
            ll comp_B = upper_bound(vals.begin(), vals.end(), end_val) - vals.begin() - 1;
            
            // If the range is valid, query the tree
            if (comp_A > comp_B) {
                cout << "0 ";
            } else {
                cout << st.queryTree(comp_A, comp_B) << " ";
            }
        }
    }
    

    return 0;
}