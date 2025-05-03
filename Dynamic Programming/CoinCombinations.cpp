#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007
typedef long long ll;

typedef vector<ll> vll;

int solve(vector<int>&coins, vector<ll>&dp, int x){
    if(x == 0) return 1;
    if(dp[x]!=-1) return dp[x];
    ll sum = 0;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i] >= 0){
            sum += solve(coins, dp, x-coins[i])%MOD;
        }
    }
    return dp[x] = sum%MOD;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<ll> dp(x+1, -1);
    cout<<solve(coins, dp, x); 
    return 0;
}