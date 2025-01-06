#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

struct CompareFirst {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

int main(){
    int n;
    cin>>n;
    vll nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    stack<pair<int,int>> s;
    s.push({0,0});
    for(int i=0;i<n;i++){
        if(nums[i] > s.top().first){
            cout<<s.top().second<<" ";
            s.push({nums[i],i+1});
        }
        else {
            while(s.top().first >= nums[i]){
                s.pop();
            }
            if(s.top().first == 0){
                cout<<0<<" ";
            }
            else cout<<s.top().second<<" ";
            s.push({nums[i],i+1});
        }
    }
    
    return 0;
}