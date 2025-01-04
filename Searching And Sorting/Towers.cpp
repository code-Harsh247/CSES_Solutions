#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;


int main(){
    ll n;
    cin>>n;
    vll cubes(n);
    for(ll i=0;i<n;i++){
        cin>>cubes[i];
    }
    multiset<ll> towers;
    towers.insert(cubes[0]);
    for(ll i=1;i<n;i++){
        auto it = towers.lower_bound(cubes[i] + 1); // Strictly greater than cubes[i]
        if(it!=towers.end()) towers.erase(it);
        towers.insert(cubes[i]);
        
    }
    cout<<towers.size()<<endl;
    
    return 0;
}