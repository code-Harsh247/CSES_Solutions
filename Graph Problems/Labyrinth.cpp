#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

string construct_path(vector<vector<pair<int, int>>> &parent, pair<int, int> src, pair<int, int> dest) {
    string path = "";
    pair<int, int> current = dest;
    vector<char> direction_chars = {'D', 'R', 'U', 'L'};
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (current != src) {
        pair<int, int> prev = parent[current.first][current.second];
        for (int i = 0; i < 4; ++i) {
            if (prev.first + directions[i].first == current.first &&
                prev.second + directions[i].second == current.second) {
                path += direction_chars[i];
                break;
            }
        }
        current = prev;
    }
    reverse(path.begin(), path.end());
    return path;
}

string bfs(vector<vector<char>> &labyrinth, pair<int, int> src, pair<int, int> &dest) {
    int n = labyrinth.size();
    int m = labyrinth[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    q.push(src);
    visited[src.first][src.second] = 1;

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && labyrinth[nx][ny] != '#') {
                visited[nx][ny] = 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
                if (labyrinth[nx][ny] == 'B') {
                    dest = {nx, ny};
                    return construct_path(parent, src, dest);
                }
            }
        }
    }

    return "notFound";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> labyrinth(n, vector<char>(m));
    pair<int, int> src, dest;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') src = {i, j};
        }
    }

    string path = bfs(labyrinth, src, dest);

    if (path != "notFound")
        cout << "YES\n" << path.length() << "\n" << path << endl;
    else
        cout << "NO" << endl;

    return 0;
}
