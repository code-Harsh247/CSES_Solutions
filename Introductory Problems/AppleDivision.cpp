#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

ll solve(vll &p, ll sum1, ll sum2, int ind, int n){
    if(ind==n) return abs(sum1-sum2);
    ll take = solve(p, sum1+p[ind], sum2, ind+1, n);
    ll notTake = solve(p, sum1, sum2+p[ind], ind+1, n);
    return min(take, notTake);

}

int main(){
    ll n;
    cin>>n;
    vll p(n);
    ll sum1 = 0, sum2= 0;
    for(ll i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<solve(p,sum1,sum2,0,n)<<endl;
    return 0;
}