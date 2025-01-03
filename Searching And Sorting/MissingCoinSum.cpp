#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    vll coins(n);
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin(), coins.end());
    ll ans =1;
    for(int i=0;i<n;i++){
        if(ans < coins[i]){
            break;
        }
        else ans+=coins[i];
    }
    cout<<ans<<endl;
    
    
    return 0;
}