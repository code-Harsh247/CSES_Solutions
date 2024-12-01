#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void printList(vector<ll> &v){
    cout<<v.size()<<endl;
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(sum% 2!=0) cout<<"NO"<<endl;
    else {
       sum /= 2;
       vector<ll> v1,v2;
       for(ll i=n;i>=1;i--){
            if(sum-i >= 0) {
                v1.push_back(i);
                sum = sum - i;
            }
            else v2.push_back(i);
       }
       cout<<"YES"<<endl;
       printList(v1);
       printList(v2); 
    }
    return 0;
}