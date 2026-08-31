#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

ll dp[20][2][11][2];

ll solve(string&s, int idx, bool tight, int prev, bool lz){
    
    if(idx == (ll)s.size()) return 1;
    if(dp[idx][tight][prev][lz]!=-1) return dp[idx][tight][prev][lz];
    ll ub = (tight)? s[idx]-'0':9;
    ll lb = 0;
    ll res = 0;
    for(int dig=lb;dig<=ub;dig++){
        if(dig == prev && !lz) continue;
        bool nextTight = (tight && dig==ub);
        bool nextLz = (lz && dig==0);
        res += solve(s,idx+1,nextTight,dig,nextLz);
    }
    return dp[idx][tight][prev][lz] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;
    string r = to_string(b);
    string l = to_string(a-1);
    memset(dp,-1, sizeof(dp));
    ll ansR = solve(r,0,1,10,1);
    memset(dp,-1, sizeof(dp));
    ll ansL = (a==0)? 0 : solve(l,0,1,10,1);

    cout<<ansR-ansL<<endl;
    
    return 0;
}