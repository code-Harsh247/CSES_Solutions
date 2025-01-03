#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        int enter,leave;
        cin>>enter>>leave;
        events.push_back({enter,1});
        events.push_back({leave,-1});
    }
    sort(events.begin(),events.end());
    int maxAudience = 0;
    int audience = 0;
    for(auto it: events){
        audience += it.second;
        if(audience>maxAudience) maxAudience = audience;
    }
    cout<<maxAudience<<endl;

    return 0;
}