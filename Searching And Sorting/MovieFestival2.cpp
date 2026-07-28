#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<pll> movies(n);
    for(int i=0;i<n;i++) cin>>movies[i].first>>movies[i].second;
    sort(movies.begin(),movies.end(),[](const auto& a, const auto&b){
        return a.second<b.second;
    });
    multiset<ll> members;
    ll count = 0;
    for(int i=0;i<k;i++) members.insert(0);
    for(int i=0;i<n;i++){
        ll curMovieStart = movies[i].first;
        ll currMovieEnd = movies[i].second;
        auto it = members.upper_bound(curMovieStart);
        if(it == members.begin()) continue;
        else{
            it--;
            members.erase(it);
            members.insert(currMovieEnd);
            count++;
        }
    }
    cout<<count<<endl;


    return 0;
}