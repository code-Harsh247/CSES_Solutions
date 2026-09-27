#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

void solve(int n, int a, int b){
    if(a+b>n || (a==0 && b>0) || (b==0 && a>0)){
        cout<<"NO"<<endl;
        return;
    }
    
    cout<<"YES"<<endl;

    vector<int> p1(n), p2(n);
    int ties = n - (a+b);
    for(int i=0;i<ties;i++){
        p1[i] = i+1;
        p2[i] = i+1;
    }
    int start = ties+1;
    int movesLeft = a+b;

    for(int i=0;i<movesLeft;i++){
        p2[ties+i] = start+i;
        p1[ties+i] = start + (i+b)%movesLeft;
    }

    for(int i=0;i<n;i++){
        cout<<p1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<p2[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        solve(n,a,b);
    }

    return 0;
}