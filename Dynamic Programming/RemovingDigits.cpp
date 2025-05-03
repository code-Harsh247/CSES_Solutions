#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

vector<int> strip(int n){
    vector<int> result;
    while(n > 0){
        int digit = n % 10;
        if(digit != 0) result.push_back(digit); // skip 0s
        n /= 10;
    }
    return result;
}

int solve(vector<int> digits, vector<int> &dp, int target){
    if(target == 0) return 0;
    if(dp[target] != -1) return dp[target];
    int mini = INT_MAX;
    int imm = 0;
    for(int digit: digits){
        if(target - digit >=0){
            imm = solve(strip(target-digit), dp, target- digit);
        }
        mini = min(1+imm,mini);
    }
    return dp[target] = mini;
}

int main(){
    int n;
    cin >> n;
    vector<int> digits = strip(n);
    vector<int> dp(n + 1, -1);
    cout << solve(digits, dp, n) << endl;
    return 0;
}
