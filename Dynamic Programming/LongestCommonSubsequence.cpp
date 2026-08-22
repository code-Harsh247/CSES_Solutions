#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m;
    cin>>n>>m;
    vector<int> seq1(n),seq2(m);
    for(int i=0;i<n;i++) cin>>seq1[i];
    for(int j=0;j<m;j++) cin>>seq2[j];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // for(int i=0;i<n;i++) dp[i][0] = 0;
    // for(int i=0;i<m;i++) dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seq1[i-1] == seq2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n,j=m;
    vector<int> lcs;
    cout<<dp[n][m]<<endl;
    while(i>0 && j>0){
        if(seq1[i-1] == seq2[j-1]){
            i--;
            j--;
            lcs.push_back(seq1[i]);
        }
        else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    for(auto it : lcs) cout<<it<<" ";
    return 0;
}