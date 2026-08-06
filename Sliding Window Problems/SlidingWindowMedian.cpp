#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vll nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    ll l=0, r=0;
    ll count = 0;
    ordered_set st;
    while(r<n){
        st.insert({nums[r], r});
        count++;
        while(count>k){ 
            st.erase({nums[l], l});
            count--;
            l++;
        }
        if(count==k){
            ll midInd;
            if(st.size()%2 == 0){
                midInd = (st.size()/2)-1;
            }
            else midInd = (st.size()/2);
            auto it = st.find_by_order(midInd);
            cout<<it->first<<" ";
        }
        r++;
    }
    return 0;
}