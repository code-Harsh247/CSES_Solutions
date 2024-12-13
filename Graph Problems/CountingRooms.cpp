#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;

typedef vector<ll> vll;

void bfs(vector<vector<char>> &building,vector<vector<int>> &visited, pair<int,int> src){
    int n = building.size();
    int m = building[0].size();
    queue<pair<int,int>> q;
    q.push(src);
    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto dir: directions){
            int nx = x + dir.first;
            int ny = y+ dir.second;
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(building[nx][ny] == '.' && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> building(n,vector<char>(m));
    vector<pair<int,int>> floors;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>building[i][j];
            if(building[i][j] == '.') floors.push_back({i,j});
        }
    }
    vector<vector<int>> visited(n,vector<int>(m,0));
    int rooms = 0;
    for(auto it : floors){
        int i = it.first;
        int j = it.second;
        if(building[i][j]=='.' && !visited[i][j]){
            rooms++;
            bfs(building,visited,{i,j});
        }
        
    }
    cout<<rooms<<endl; 
    return 0;
}