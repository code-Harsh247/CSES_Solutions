#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

set<pair<ll,ll>> left_set, right_set;
ll left_sum=0, right_sum =0;
int k;

void balance(){
    int left_target = (k+1)/2;
    while((int)left_set.size() < left_target && !right_set.empty()){
        auto element = right_set.begin();
        left_set.insert(*element);
        left_sum+=element->first;
        right_sum-=element->first;
        right_set.erase(element);
    }
    while((int)left_set.size() > left_target){
        auto element = prev(left_set.end());
        right_set.insert(*element);
        right_sum += element->first;

        left_sum -= element->first;
        left_set.erase(element);
    }
}

void add_element(ll val, ll idx){
    if(left_set.empty() || val <= left_set.rbegin()->first){
        left_set.insert({val, idx});
        left_sum+=val;
    }
    else{
        right_set.insert({val, idx});
        right_sum+=val;
    }
    balance();
} 

void remove_element(ll val, ll idx){
    if(left_set.count({val, idx})){
        left_set.erase({val,idx});
        left_sum-=val;
    }
    else{
        right_set.erase({val, idx});
        right_sum-=val;
    }
    balance();
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n>>k;
    vll nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    for(int i=0;i<n;i++){
        add_element(nums[i], i);
        if(i>=k){
            remove_element(nums[i-k],i-k);
        }
        if(i>=k-1){
            ll median = left_set.rbegin()->first;
            ll left_count = left_set.size();
            ll right_count = right_set.size();

            ll cost = (median*left_count - left_sum) + (right_sum - median*right_count);
            cout<<cost<<" ";
        }
    }
    return 0;
}