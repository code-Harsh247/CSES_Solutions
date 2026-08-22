#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

ll solve(vector<ll>&list,ll l, ll r, vector<vector<ll>>&dp){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    ll left = list[l] - solve(list,l+1,r, dp);
    ll right = list[r] - solve(list,l,r-1, dp);

    return dp[l][r] = max(left, right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> list(n);
    for(ll i=0;i<n;i++){
        cin>>list[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n,-1));
    ll total = accumulate(list.begin(), list.end(), 0LL);
    ll maxDiff = solve(list,0,n-1,dp);
    ll maxScore = (total + maxDiff)/2;
    cout<<maxScore<<endl;


    return 0;
}