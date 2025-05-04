#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m+2, 0));
    for(ll i=0;i<n;i++){
        if(i == 0){
            if(nums[i] == 0){
                for(ll v = 1;v<=m;v++){
                    dp[i][v] = 1;
                }
            }
            else dp[i][nums[i]] = 1;
        }
        else{
            if(nums[i] == 0){
                for(ll val = 1;val<=m;val++){
                    dp[i][val] = (dp[i-1][val-1] + dp[i-1][val] + dp[i-1][val+1])%MOD;
                }
            }
            else dp[i][nums[i]] = (dp[i-1][nums[i]-1] + dp[i-1][nums[i]] + dp[i-1][nums[i]+1])%MOD;
        }
    }
    long long ans = 0;
    for(ll i=1;i<=m;i++){
        ans = (ans + dp[n-1][i])%MOD;
    }
    cout<<ans;
    return 0;
}