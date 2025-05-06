#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

ll solve(ll ind, ll target, vector<vector<ll>> &dp){
    if(target == 0) return 1;
    if(ind == 1){
        return target == 1? 1:0;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    ll take  = 0, notTake = 0;
    if(target - ind >= 0){
        take = solve(ind-1, target-ind, dp);
    }
    notTake = solve(ind-1, target, dp);
    return dp[ind][target] = (take + notTake)%MOD;
}

int main(){
    ll n;
    cin>>n;
    ll target = n*(n+1)/2;
    if(target % 2 != 0 ){
        cout<<0<<endl;
    }
    else{
        vector<vector<ll>> dp(n+1, vector<ll>(target+1, -1));
        ll totalWays = solve(n, target / 2, dp);
        ll inverse2 = 500000004; // since 2^(-1) mod 1e9+7 = 500000004
        cout << (totalWays * inverse2) % MOD;
    }

    return 0;
}