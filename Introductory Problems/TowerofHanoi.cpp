#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void solve(vector<pair<int,int>> &moves, int l,int m,int r, int n){
    if(n==1){
        moves.push_back({l,r});
        return;
    }
    solve(moves, l,r,m,n-1);
    moves.push_back({l,r});
    solve(moves,m,l,r,n-1);
}


int main(){
    int n;
    cin>>n;
    int l=1, m=2, r=3;
    vector<pair<int, int>> moves;
    solve(moves, l, m, r, n);
    cout<<moves.size()<<endl;
    for(auto p : moves){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}