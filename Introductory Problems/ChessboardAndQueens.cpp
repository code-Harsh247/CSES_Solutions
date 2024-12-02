#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;

void solve(int &ans, int row, vector<vector<char>> &board, vector<bool> &colOccupy, vector<bool> &diag1, vector<bool> &diag2) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '*' || colOccupy[col] || diag1[row + col] || diag2[row - col + 7]) 
            continue;

        // Mark the current column and diagonals as occupied
        colOccupy[col] = diag1[row + col] = diag2[row - col + 7] = true;

        // Recur to place queen in the next row
        solve(ans, row + 1, board, colOccupy, diag1, diag2);

        // Backtrack and unmark
        colOccupy[col] = diag1[row + col] = diag2[row - col + 7] = false;
    }
}

int main() {
    vector<vector<char>> board(8, vector<char>(8, '.'));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    // Initialize the occupancy trackers
    vector<bool> colOccupy(8, false);
    vector<bool> diag1(15, false);  // 2*n - 1 for diagonals
    vector<bool> diag2(15, false); // 2*n - 1 for diagonals

    int ans = 0;
    solve(ans, 0, board, colOccupy, diag1, diag2);

    // Print the result
    cout << ans << endl;

    return 0;
}
