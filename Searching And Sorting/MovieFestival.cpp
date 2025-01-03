#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> intervals;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        intervals.push_back({start,end});
    }
    sort(intervals.begin(), intervals.end(),compare);
    int finishingTime = -1,count = 0;
    for(auto it : intervals){
        int start = it.first;
        int end = it.second;
        if(start >= finishingTime){
            finishingTime = end;
            count++;
        }
    }
    cout<<count<<endl;  

    return 0;
}