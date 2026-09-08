#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
 
int up[200005][20];
 
int solve(int node, int k){
    for(int bit=0;bit<=19;bit++){
        if((1<<bit)&k){
            if(node!=-1) node = up[node][bit];
        }
    }
    return node;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,q;
    cin>>n>>q;
    vector<int> bosses(n+1);
    bosses[1] = 0;
    memset(up, -1, sizeof(up));
    for(int i=2;i<=n;i++){
        int b;
        cin>>b;
        bosses[i]=b;
        up[i][0] = b;
    }
    for(int node=1;node<=n;node++){
        for(int k=1;k<20;k++){
            if(up[node][k-1]!=-1) up[node][k] = up[up[node][k-1]][k-1];
        }
    }
    for(int i=0;i<q;i++){
        int node,k;
        cin>>node>>k;
        cout<<solve(node,k)<<"\n";
    }
    return 0;
}