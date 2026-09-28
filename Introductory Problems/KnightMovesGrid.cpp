#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> moves = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pii> q;
    
    q.push({0, 0});
    dist[0][0] = 0; 
    
    while(!q.empty()){
        auto [row, col] = q.front();
        q.pop();
        
        for(auto move : moves){
            int r = row + move.first;
            int c = col + move.second;
            
            if(r >= 0 && r < n && c >= 0 && c < n && dist[r][c] == -1){
                dist[r][c] = dist[row][col] + 1;
                q.push({r, c});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}