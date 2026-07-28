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
    for(int i=0;i<n;i++) cin>>nums[i];
    ll currSum=0,count=0;
 
    map<ll,ll> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++){
        currSum += nums[i];
        ll rem = ((currSum%n)+n)%n;
        if(mp.find(rem) != mp.end()){
            count += mp[rem];
        }
        mp[rem]++;
    }
    cout<<count<<endl;
 
 
    return 0;
}