#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    vll readTimes(n);
    for(ll i=0;i<n;i++){
        cin>>readTimes[i];
    }
    ll totalReadTime  = accumulate(readTimes.begin(), readTimes.end(),0LL);
    ll bigBook = *max_element(readTimes.begin(), readTimes.end());
    ll ktime = totalReadTime - bigBook;
    if(bigBook > ktime) cout<<bigBook*2<<endl;
    else cout<<totalReadTime<<endl;

    return 0;
}