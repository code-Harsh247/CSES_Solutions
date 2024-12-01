#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

ll solve(ll n){
    if(n==0) return 0;
    return n/5 + solve(n/5);
}

//Find number of 5's

int main(){
    ll n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}