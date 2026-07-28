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
 
    ll n,k; 
    cin>>n>>k;
    vll nums(n);
    for(ll i=0;i<n;i++) cin>>nums[i];
    map<ll,ll> freq;
    ll distinct=0;
    ll count = 0,l=0;
    for(ll r=0;r<n;r++){
        if(freq[nums[r]]==0){
            distinct++;
        }
        freq[nums[r]]++;
        while(distinct>k){
            freq[nums[l]]--;
            if(freq[nums[l]]==0) distinct--;
            l++;
        }
        count += r-l+1;
    }
    cout<<count<<endl;
 
 
    return 0;
}