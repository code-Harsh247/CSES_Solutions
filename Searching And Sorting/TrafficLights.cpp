#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

//find the gap that is going to be removed due to addition of new light.

int main(){
    int n,x;
    cin>>x>>n;
    set<ll> lights;
    lights.insert(0);
    lights.insert(x);
    multiset<ll> gaps;
    gaps.insert(x);
    for(int i=0;i<n;i++){
        ll pos;
        cin>>pos;
        auto ub = lights.upper_bound(pos);
        auto lb = prev(ub); //returns the previous iterator
        ll lbValue = *lb, ubValue = *ub;
        lights.insert(pos);
        auto gapIterator = gaps.find(ubValue - lbValue);
        gaps.erase(gapIterator);
        gaps.insert(pos - lbValue);
        gaps.insert(ubValue - pos);
        auto maxGap = --gaps.end();
        cout<<*maxGap<<endl;
    }
    return 0;
}