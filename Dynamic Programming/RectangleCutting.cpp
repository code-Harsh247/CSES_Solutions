#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
 
int solve(int l, int b, vector<vector<int>>&dp){
    if(l == b) return 0;
    if(dp[l][b]!=-1) return dp[l][b];
 
    int minCutlateral = INT_MAX;
    for(int i=1;i<l;i++){
        int currCut = 1 + solve(i,b,dp) + solve(l-i,b,dp);
        minCutlateral = min(minCutlateral, currCut);
    }
    int minCutVertical = INT_MAX;
    for(int i=1;i<b;i++){
        int currCut = 1 + solve(l,i,dp) + solve(l,b-i,dp);
        minCutVertical = min(minCutVertical, currCut);
    }
    return dp[l][b] = min(minCutVertical,minCutlateral);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            int cuts = 1e9;
            for(int k=1; k<i;k++){
                cuts = min(cuts, 1 + dp[k][j] + dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                cuts = min(cuts, 1+dp[i][k]+dp[i][j-k]);
            }
            dp[i][j] = cuts;
        }
    }
    cout<<dp[a][b]<<endl;
 
    return 0;
}