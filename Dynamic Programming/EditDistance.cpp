#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

// int solve(string word1, string word2, int ptr1, int ptr2, vector<vector<int>> &dp){
//     if(ptr1 < 0){
//         return ptr2+1;
//     }
//     if(ptr2 < 0){
//         return ptr1+1;
//     }
//     if(dp[ptr1][ptr2]!=-1) return dp[ptr1][ptr2];
//     if(word1[ptr1] != word2[ptr2]){
//         int insert = solve(word1, word2, ptr1, ptr2-1, dp);
//         int del = solve(word1, word2, ptr1-1, ptr2,dp);
//         int replace = solve(word1, word2, ptr1-1, ptr2-1, dp);

//         return dp[ptr1][ptr2] =  1 + min(insert, min(del, replace));
//     }
//     else return dp[ptr1][ptr2] = solve(word1, word2, ptr1-1, ptr2-1, dp);
    

// }

int main(){
    string word1, word2;
    cin>>word1>>word2;
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1] != word2[j-1]){
                int insert = dp[i][j-1];
                int del = dp[i-1][j];
                int replace = dp[i-1][j-1];
                dp[i][j] = 1 + min(insert, min(del, replace));
            }
            else dp[i][j] = dp[i-1][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}