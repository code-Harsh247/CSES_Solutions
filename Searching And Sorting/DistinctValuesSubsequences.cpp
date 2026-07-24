#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vll nums(n);
    unordered_map<ll, ll> freq;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        freq[nums[i]]++;
    }
    ll ans = 1;
    for(auto it : freq){
        ll frequency = it.second;
        ans = (ans*(frequency+1))%MOD;
    }
    cout<<ans-1<<endl;


    return 0;
}