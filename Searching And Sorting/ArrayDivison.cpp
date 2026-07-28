#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

bool check(vll&nums, ll maxSum, ll k){
    ll partitions = 1;
    ll n = nums.size();
    ll currSum =0;
    for(int i=0;i<n;i++){
        if(currSum + nums[i] > maxSum){
            currSum = nums[i];
            partitions++;
        }
        else currSum += nums[i];
    }
    // cout<<maxSum<<" "<<partitions<<endl; 
    if(partitions<=k) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;
    vll nums(n);
    for(ll i=0;i<n;i++) cin>>nums[i];
    ll low = *max_element(nums.begin(), nums.end());
    ll high = accumulate(nums.begin(), nums.end(), 0LL);
    ll ans = -1;
    while(low<=high){
        ll mid = low + (high-low)/2;
        if(check(nums, mid, k)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans;

    return 0;
}