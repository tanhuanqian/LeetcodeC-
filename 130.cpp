#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int M, N, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] != 'O') return;
        board[x][y] = '#';
        for (auto &dir : dirs) dfs(board, x + dir[0], y + dir[1]);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        M = board.size(), N = board[0].size();
        for (int i = 0; i < M; ++i) {
            dfs(board, i, 0);
            dfs(board, i, N - 1);
        }
        for (int j = 0; j < N; ++j) {
            dfs(board, 0, j);
            dfs(board, M - 1, j);
        }
        for (auto &row : board) {
            for (auto &cell : row) {
                cell = cell == '#' ? 'O' : 'X';
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> elements = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    sol.solve(elements);
    for(int i = 0; i < elements.size(); i++){
        for(int j = 0; j < elements[i].size(); j++){
            cout << elements[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
