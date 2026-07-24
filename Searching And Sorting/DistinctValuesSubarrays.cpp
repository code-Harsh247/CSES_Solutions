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
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int left=0, right=0;
    set<ll> seen;
    ll count =0;
    while(right<n){
        if(seen.count(nums[right]) == 0){
            seen.insert(nums[right]);
            count += right - left + 1;
            right++;
        }
        else{
            seen.erase(nums[left++]);
        }
    }
    cout<<count<<endl;
    return 0;
}