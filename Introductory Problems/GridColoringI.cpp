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

    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m)), final(n,vector<char>(m));
    unordered_set<char> colors = {'A','B','C','D'};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    } 
    int dx[] = {0,-1};
    int dy[] = {-1,0};
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            unordered_set<char> temp = colors;
            temp.erase(grid[row][col]);
            for(int i=0;i<2;i++){
                int r = row+dx[i];
                int c = col+dy[i];
                if(r>=0 && r<n && c>=0 && c<m){
                    temp.erase(final[r][c]);
                }
            }
            final[row][col] = *temp.begin();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<final[i][j];
        }
        cout<<endl;
    }

    return 0;
}