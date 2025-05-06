#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n;
    cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<ll> bs;
    bs.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i] > bs.back()){
            bs.push_back(nums[i]);
        }
        else{
            auto ptr = lower_bound(bs.begin(), bs.end(), nums[i]);
            ll ind = ptr - bs.begin();
            bs[ind] = nums[i]; 
        }
    }
    cout<<bs.size();
    return 0;
}