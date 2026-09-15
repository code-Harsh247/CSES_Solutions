#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c == '*'){
                prefix[i][j] = 1+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
            else prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        int res = prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1];
        cout<<res<<"\n";
    }

    return 0;
}