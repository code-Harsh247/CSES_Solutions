#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n,x;
    cin>>n>>x;
    map<int,int> compliments;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        if(compliments.count(x-value)){
            cout<<i+1<<" "<<compliments[x-value]<<endl;
            return 0;
        }
        else compliments[value] = i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}