#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int solve(vector<vector<char>> &grid, vector<vector<int>>&dp, int i, int j){
    if(i<0 || j<0) return 0;
    if(i == 0 && j == 0) return 1;
    if(grid[i][j] == '*') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0, left= 0;
    if(i>0){
        up = solve(grid, dp, i-1, j);
    }
    if(j>0){
        left = solve(grid, dp, i, j-1);
    }
    return dp[i][j] = (up + left)%MOD;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n,-1));
    if(grid[n-1][n-1] == '*' || grid[0][0] == '*'){
        cout<<0;
    }
    else cout<<solve(grid, dp, n-1, n-1);
    
    return 0;
}