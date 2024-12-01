#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0){
            n = n/2;
        }
        else n = 3*n+1;
    }
    cout<<n<<endl;
    return 0;
}