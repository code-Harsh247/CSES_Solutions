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
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vll input(n);
    generateInput(input, x,a,b,c,n);

    vll pref(n,0), suff(n,0);
    for(int i=0;i<n;i++){
        if(i%k == 0){
            pref[i] = input[i];
        }
        else pref[i] = pref[i-1] | input[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1 || (i+1)%k==0){
            suff[i] = input[i];
        }
        else suff[i] = suff[i+1] | input[i];
    }
    ll ans = 0;
    for(int i=0;i<=n-k;i++){
        ll currOR = suff[i] | pref[i+k-1];
        ans ^= currOR;
    }
    cout<<ans<<endl;
    
    return 0;
}