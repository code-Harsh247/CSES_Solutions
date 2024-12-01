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
        ll y,x;
        cin>>y>>x;
        if(y>x){
            if(y%2 == 0){
                //right to left
                cout<< y*y - x+1;
            }
            else {
                //left to right
                cout<<((y-1)*(y-1)+1) + x -1;
            }
        }
        else {
            if(x%2 == 0){
                //bottom to top
                cout<<((x-1)*(x-1)+1) + y -1;
            }
            else {
                //top to bottom
                cout<< x*x - y +1;
            }
        }
        cout<<endl;
    }
    return 0;
}