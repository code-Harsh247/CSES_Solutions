#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int solve(vector<ll> &dp, int target){
    if(target == 0) return 1;
    if(dp[target] != -1) return dp[target];
    ll sum = 0;
    for(int i=1;i<=6;i++){
        if(target - i >= 0){
            sum += solve(dp,target-i)%MOD;
        }
    }
    return dp[target] = sum%MOD;
}

int main(){
    int target;
    cin>>target;
    vector<ll> dp(target+1,-1);
    cout<<solve(dp,target);

    return 0;
}