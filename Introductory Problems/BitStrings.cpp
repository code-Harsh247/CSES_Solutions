#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    ll n;
    cin>>n;
    ll temp = 1;
    while(n--){
        temp = (temp*2)%MOD;
    }
    cout<<temp<<endl;
    return 0;
}