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

    ll l =0, r=0;
    ll count =0;
    ll ans = 0;
    ll xori = 0;
    while(r<n){
        xori = xori^input[r];
        count++;
        while(count>k){
            xori = xori^input[l];
            l++;
            count--;
        }
        if(count == k) ans = ans^xori;
        r++;
    } 
    cout<<ans<<endl; 
    return 0;
}