#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int solve(vector<int> &coins, int target, vector<vector<int>> &dp, int ind){
    if (target == 0) return 1;
    if (ind == 0) return coins[0] == target ? 1 : 0;
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int take = 0, notTake = 0;
    if(target - coins[ind] >= 0){
        take = solve(coins, target-coins[ind], dp, ind-1);
    }
    notTake = solve(coins, target, dp, ind-1);
    return dp[ind][target] = take + notTake;

}


int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    int sum = 0;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        mini = min(mini, coins[i]);
        sum += coins[i];
    }
    vector<int> result;
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    for(int i=mini;i<=sum;i++){
        int res = solve(coins, i, dp, coins.size()-1);
        if(res!=0){
            result.push_back(i);
        }
    }
    cout<<result.size()<<endl;
    for(auto res : result){
        cout<< res<<" ";
    }

    return 0;
}