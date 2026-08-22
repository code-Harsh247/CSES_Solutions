#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O for CSES
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    string result = "";
    result += grid[0][0];

    // Maintain a list of the "best" squares we are currently standing on
    vector<pair<int, int>> active;
    active.push_back({0, 0});

    // visited array prevents paths from overlapping and blowing up the time complexity
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    // A path from (0,0) to (n-1, n-1) takes exactly 2n - 2 steps
    for (int step = 0; step < 2 * n - 2; step++) {
        char min_char = '{'; // Use ASCII character just above 'z' as starting min

        // Pass 1: Look at all valid neighbors to find the absolute smallest letter
        for (auto cell : active) {
            int r = cell.first;
            int c = cell.second;
            
            if (r + 1 < n) min_char = min(min_char, grid[r + 1][c]);
            if (c + 1 < n) min_char = min(min_char, grid[r][c + 1]);
        }

        result += min_char;

        // Pass 2: Filter and create the next batch of active squares
        vector<pair<int, int>> next_active;
        for (auto cell : active) {
            int r = cell.first;
            int c = cell.second;

            // Only move down if it has the optimal letter AND hasn't been visited
            if (r + 1 < n && grid[r + 1][c] == min_char && !visited[r + 1][c]) {
                visited[r + 1][c] = true;
                next_active.push_back({r + 1, c});
            }
            
            // Only move right if it has the optimal letter AND hasn't been visited
            if (c + 1 < n && grid[r][c + 1] == min_char && !visited[r][c + 1]) {
                visited[r][c + 1] = true;
                next_active.push_back({r, c + 1});
            }
        }
        
        // Step forward
        active = next_active;
    }

    cout << result << "\n";

    return 0;
}