#include <bits/stdc++.h>
using namespace std;

// Correctly mapped directions: Down, Right, Up, Left
int dy[] = {1, 0, -1, 0}; 
int dx[] = {0, 1, 0, -1};
char dir_char[] = {'D', 'R', 'U', 'L'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    // Using strings is slightly faster/easier to read for grids
    vector<string> grid(n);
    queue<tuple<int,int,int>> q;
    pair<int,int> start;
    
    vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));

    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                q.push({i, j, 0});
                monsterTime[i][j] = 0; // FIX 3: Initialize start time to 0
            }
            if(grid[i][j] == 'A') start = {i, j};
        }
    }

    // 1. Monster BFS
    while(!q.empty()){
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int time = get<2>(q.front());
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            
            // FIX 1: Check grid[nr][nc], and ensure it's not a wall
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#'){
                if(time + 1 < monsterTime[nr][nc]){
                    monsterTime[nr][nc] = time + 1;
                    q.push({nr, nc, time + 1});
                }
            }
        }
    }

    // 2. Player BFS
    // FIX 4: Corrected vector types
    vector<vector<char>> directions(n, vector<char>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while(!q.empty()){
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int time = get<2>(q.front());
        q.pop();
        
        // Escape condition
        if(r == 0 || r == n - 1 || c == 0 || c == m - 1){
            cout << "YES\n"; // FIX 5: Missing YES output
            string path = "";
            
            while(r != start.first || c != start.second){
                char d = directions[r][c];
                path += d;
                // FIX 6: Backtrack in the OPPOSITE direction of the move
                if(d == 'U') r++;       // We moved UP to get here, so go DOWN to find parent
                else if(d == 'D') r--;  // Moved DOWN, so go UP
                else if(d == 'L') c++;  // Moved LEFT, so go RIGHT
                else if(d == 'R') c--;  // Moved RIGHT, so go LEFT
            }
            
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            
            // FIX 2: Ensure we don't visit the same cell twice using !visited[nr][nc]
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && !visited[nr][nc]){
                if(time + 1 < monsterTime[nr][nc]){
                    visited[nr][nc] = true;
                    directions[nr][nc] = dir_char[i];
                    
                    // FIX: Push time + 1, not time
                    q.push({nr, nc, time + 1});
                }
            }
        }
    }

    cout << "NO\n";
    return 0;