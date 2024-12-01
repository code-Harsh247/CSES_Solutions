#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n+1, -1);
    for(ll i = 1; i<=n-1; i++){
        ll temp;
        cin>>temp;
        v[temp] = 1;
    }
    for(ll i = 1; i<=n; i++){
        if(v[i]==-1){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}