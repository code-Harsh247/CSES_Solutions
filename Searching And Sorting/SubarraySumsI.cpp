#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n,x;
    cin>>n>>x;
    vll nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> prefixSum(n+1);
    prefixSum[0] = 0;
    for(int i=0;i<n;i++){
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }
    int ptr1 = 0, ptr2 = 1,sum =0,count=0;
    while(ptr2<=n){
        sum = prefixSum[ptr2] - prefixSum[ptr1];
        if(sum==x){
            count++;
            ptr2++;
        }
        else if(sum>x){
            ptr1++;
        }
        else ptr2++;

        if(ptr1 == ptr2){
            ptr2++;
        }
    }
    cout<<count<<endl;
    return 0;
}