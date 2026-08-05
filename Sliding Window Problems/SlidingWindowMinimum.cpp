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
    deque<ll> dq;
    ll ans =0;
    for(int i=0;i<n;i++){
        while(!dq.empty() && input[dq.back()] >= input[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(!dq.empty() && dq.front() < i-k+1){
            dq.pop_front();
        }
        if(i >= k-1) ans = ans^input[dq.front()];
    }
    cout<<ans<<endl;
    
    return 0;
}