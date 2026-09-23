#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

ll solve(ll n){
    ll count =0;
    for(ll i=0;i<60;i++){
        if ((1LL << i) > n + 1) break;
        ll r = (n+1)%(1LL<<(i+1));
        ll onesInR = max(0LL,r-(1LL<<i));
        ll completeCycles = (n+1)/(1LL<<(i+1));
        ll onesInCompleteCycles = (1LL<<i)*(completeCycles);
        count += onesInR + onesInCompleteCycles;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    cout<<solve(n)<<endl;

    return 0;
}