#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n,t;
    cin>>n>>t;
    vll prodTimes(n);
    for(int i=0;i<n;i++) cin>>prodTimes[i];

    if(n == 1){
        cout<<t*prodTimes[0]<<endl;
        return 0;
    }

    ll l = 0, r = 1e18;
    ll ans,prd;
    while(l<r-1){
        ll mid = (l+r)/2;
        prd = 0;
        for(ll i=0;i<n;i++) {
            if(prd>=1e18) break;
            prd+=mid/prodTimes[i];
        }
        if(prd>=t){
            ans = mid;
            r = mid;
        }
        else l = mid;
    }
    cout<<ans<<endl;
    return 0;
}