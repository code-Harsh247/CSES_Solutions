#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

vector<vector<vector<ll>>> memo;

ll solve(ll n, ll m, ll mask, ll r, ll c)
{
    if (c == m)
    {
        if(mask&(1<<m)) return 0;
        return solve(n,m,mask<<1,r+1,0);
    }
    if (r == n){
        if(mask == 0) return 1;
        else return 0;
    }
    if (memo[r][c][mask] != -1) {
        return memo[r][c][mask];
    }
    ll left_covered= mask & (1 << c);
    ll top_covered= mask & (1 << (c + 1));
    ll ways = 0;
    if (!left_covered && !top_covered)
    {
        if(c+1<m){
            ways = (ways + solve(n, m, mask ^ (1 << (c + 1)), r, c + 1))%MOD;
        }
        if(r+1<n){
            ways = (ways + solve(n, m, mask ^ (1<<(c)),r,c+1))%MOD;
        }
    }
    else if(left_covered && !top_covered){
        ways = solve(n,m,mask^(1<<c),r,c+1)%MOD;
    }
    else if(!left_covered && top_covered){
        ways = solve(n,m,mask^(1<<(c+1)),r,c+1)%MOD;
    }

    return memo[r][c][mask] = ways;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin>>n>>m;
    if ((n * m) % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (n < m) {
        swap(n, m);
    }
    memo.assign(n, vector<vector<ll>>(m, vector<ll>(1 << (m + 1), -1)));
    cout<<solve(n,m,0,0,0);

    return 0;
}