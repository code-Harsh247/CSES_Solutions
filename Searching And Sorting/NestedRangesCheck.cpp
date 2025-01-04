#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;

bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    // First, compare the first values in ascending order
    if (a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    // If the first values are the same, compare the second values in descending order
    return a.first.second > b.first.second;
}

int main(){
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> ranges(n); 
    vector<int> contains(n, 0), isContained(n, 0);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ranges[i] = {{a, b}, i};  
    }


    sort(ranges.begin(), ranges.end(), compare);

    int maxEnd = 0;

   for(int i=0;i<n;i++){
        int end = ranges[i].first.second;
        int ind = ranges[i].second;
        if(end <= maxEnd){
            isContained[ind] = 1;
        }
        maxEnd = max(maxEnd, end);
    }
    maxEnd = INT_MAX;
    for(int i=n-1;i>=0;i--){
        int end = ranges[i].first.second;
        int ind = ranges[i].second;
        if(end >= maxEnd){
            contains[ind] = 1;
        }
        maxEnd = min(maxEnd, end);
    }

    for(auto it: contains){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: isContained){
        cout<<it<<" ";
    }


    return 0;
}
