#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;
    cin >> t;
    while (t--) {
        ll a,b;
        cin>>a>>b;
        ll tx = 2*a - b;
        ll ty = 2*b - a;
        if(tx < 0 || ty < 0) cout<<"NO"<<endl;
        else if(tx%3!=0 || ty%3!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}