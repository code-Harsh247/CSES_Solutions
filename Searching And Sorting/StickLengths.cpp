#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    vll lengths(n);
    for(ll i=0;i<n;i++){
        cin>>lengths[i];
    }
    sort(lengths.begin(), lengths.end());
    ll medianIndex = n/2;
    ll median = lengths[medianIndex];
    ll sum = 0;
    for(auto it: lengths){
        sum += abs(it - median);
    }
    cout<<sum<<endl;
    
    
    return 0;
}