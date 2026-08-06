#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// PBDS Safe Multiset: storing pair<value, index>
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

#define INF 1e9
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vll nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    ordered_multiset pbds;
    ll inversions = 0;

    for(int i=0;i<k;i++){
        ll greater = pbds.size() - pbds.order_of_key({nums[i],INF});
        inversions += greater;
        pbds.insert({nums[i],i});
    }
    cout<<inversions<<" ";
    for(int i=k;i<n;i++){
        ll old_val = nums[i-k];
        ll old_idx = i-k;
        ll smaller = pbds.order_of_key({nums[old_idx],-1});
        inversions -= smaller;
        pbds.erase({old_val,old_idx});
        ll greater = pbds.size() - pbds.order_of_key({nums[i],INF});
        inversions += greater;
        pbds.insert({nums[i],i});
        cout<<inversions<<" ";
    }


    return 0;
}