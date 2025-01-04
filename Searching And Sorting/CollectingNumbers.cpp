#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n;
    cin>>n;
    vll nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    set<int> s;
    int count = 0;
    for(int num : nums){
        if(s.find(num-1)==s.end()){
            count++;
        }
        s.insert(num);
    }
    cout<<count<<endl;
    return 0;
}