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

    int n,a,b;
    cin>>n>>a>>b;
    vll nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vll prefix(n + 1, 0); // Size n+1, all initialized to 0
    for(int i=0;i<n;i++){
        prefix[i+1] = prefix[i] + nums[i];
    }
    multiset<ll> minPrefix;
    ll ans = LONG_LONG_MIN;
    for(int i=a;i<=n;i++){
        minPrefix.insert(prefix[i-a]);
        ans = max(ans, prefix[i] - *minPrefix.begin());
        if(i>=b){
            minPrefix.erase(minPrefix.find(prefix[i-b]));
        }
    }
    cout<<ans<<endl;

    return 0;
}