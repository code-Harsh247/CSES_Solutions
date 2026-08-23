#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

pair<int,int> solve(vector<int>&weights, int mask, int maxWeight,vector<pair<int,int>>&dp){
    int n = weights.size();
    if(mask == 0) return {1,0};
    if(dp[mask].first!=-1) return dp[mask];
    pair<int,int> best = {INT_MAX, INT_MAX};
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            pair<int,int> prev = solve(weights,mask^(1<<i),maxWeight,dp);
            if(prev.second + weights[i] <= maxWeight){
                prev.second += weights[i];
            }
            else{
                prev.first += 1;
                prev.second = weights[i];
            }
            best = min(best, prev);
        }
    }
    return dp[mask] = best;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int> weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    vector<pair<int,int>> dp((1<<n),{-1,-1});
    pair<int,int> result = solve(weights,(1<<n)-1,x,dp);
    cout<<result.first<<endl;
    return 0;
}