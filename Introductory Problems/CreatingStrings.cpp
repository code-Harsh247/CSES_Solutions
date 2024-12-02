#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

int main(){
    string s;
    cin>>s;
    vector<string> pr;
    sort(s.begin(),s.end());
    pr.push_back(s);
    while(next_permutation(s.begin(),s.end())){
        pr.push_back(s);
    }
    cout<<pr.size()<<endl;
    for(auto s: pr){
        cout<<s<<endl;
    }
    return 0;
}