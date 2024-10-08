#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            grid[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            grid[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};

int main(){
    Solution sol;
    int m = 3, n =7;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}