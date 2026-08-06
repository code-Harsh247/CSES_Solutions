#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

void generateInput(vll&input, ll x, ll a, ll b, ll c,ll n){
    input[0] = x;
    for(ll i=1;i<n;i++){
        input[i] = (a*input[i-1]+b)%c;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,k;
    cin>>n>>k;
    // ll x,a,b,c;
    // cin>>x>>a>>b>>c;
    vll input(n);
    for(int i=0;i<n;i++) cin>>input[i];
    // generateInput(input, x,a,b,c,n);

    ll l=0, r=0;
    map<ll,ll> mp;
    int count =0;
    while(r<n){
        mp[input[r]]++;
        count++;
        while(count>k){
            mp[input[l]]--;
            count--;
            if(mp[input[l]] == 0) mp.erase(input[l]);
            l++;
        }
        if(count == k) cout<<mp.size()<<" ";
        r++;
    }
    return 0;
}