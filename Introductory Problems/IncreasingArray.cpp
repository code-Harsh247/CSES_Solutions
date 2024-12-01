#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll out = 0, temp = v[0];
    for(ll i=1;i<n;i++){
        if(v[i]<temp){
            out += temp-v[i];
        }
        else temp = v[i];
    }
    cout<< out<< endl;
    return 0;
}