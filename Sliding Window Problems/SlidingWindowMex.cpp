#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, k;
    cin >> n >> k;
    vll nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    set<ll> missing;
    map<ll,ll> freq;
    for (int i = 0; i <= k; i++)
        missing.insert(i);
    ll l=0,r=0;
    ll count = 0;
    while(r<n){
        if(nums[r]<=k) {
            freq[nums[r]]++;
            missing.erase(nums[r]);
        }
        count++;
        while(count>k){
            if(nums[l]<=k) freq[nums[l]]--;
            count--;
            if(freq[nums[l]] == 0) {
                missing.insert(nums[l]);
                freq.erase(nums[l]); 
            }
            l++;
        }
        if(count == k){
            ll mex = *missing.begin();
            cout<<mex<<" ";
        }
        r++;
    }
    return 0;
 
}