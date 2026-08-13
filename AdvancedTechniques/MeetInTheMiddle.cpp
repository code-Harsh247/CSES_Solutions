#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

vector<ll> subsetSums(vector<ll>&nums, ll startIdx, ll endIdx){
    ll n = endIdx - startIdx + 1;
    vector<ll> result;
    for(ll mask=0;mask<(1<<n);mask++){
        ll sum = 0;
        for(ll i=0;i<n;i++){
            if(mask & (1<<i)){
                sum += nums[startIdx+i];
            }
        }
        result.push_back(sum);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;
    cin>>n>>x;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++) cin>>nums[i];
    ll n1 = n/2;
    vector<ll> partition1, partition2;
    partition1 = subsetSums(nums,0,n1-1);
    partition2 = subsetSums(nums,n1,n-1);

    sort(partition2.begin(), partition2.end());
    ll result = 0;
    for(auto s : partition1){
        ll target = x - s;
        auto lb = lower_bound(partition2.begin(), partition2.end(), target);
        auto ub = upper_bound(partition2.begin(), partition2.end(), target);
        ll count = ub - lb;
        result += count;
    }
    cout<<result<<endl;


    return 0;
}