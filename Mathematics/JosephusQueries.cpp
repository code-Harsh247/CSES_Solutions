#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

ll solve(ll n,ll k){
    if(n == 1) return 1;
    if(k<=n/2) return 2*k;
    if(n%2 == 0){
        ll res = solve(n/2,k-n/2);
        return 2*res-1;
    }
    else{
        ll res = solve(n/2+1,k-n/2);
        if(res == 1) return n;
        return 2*res-3;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin>>q;
    while(q--){
        ll n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }

    return 0;
}