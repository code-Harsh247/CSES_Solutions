#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

//Kadane's algo
int main(){
    ll n;
    cin>>n;
    vll nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }
    ll maxSum=nums[0];
    ll res=nums[0];
    for(ll i=1;i<n;i++){
        maxSum = max(maxSum +nums[i], nums[i]);
        res = max(maxSum,res);
    }
    cout<<res<<endl;
    return 0;
}