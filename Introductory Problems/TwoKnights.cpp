#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    /* In a 2*3 grid, there are 2 ways to place the knights such that they kill each other. 
    There are a total of 4(k-1)(k-2) such 2*3 grids in a k*k board.
    Total number of ways to select 2 squares = k2 choose 2 */

    for(ll i=1;i<=n;i++){
        ll k2 = i*i;
        cout<< k2*(k2-1)/2 - 4*(i-1)*(i-2)<<endl;
    }
    return 0;
}