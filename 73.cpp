#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> zerorows(m, false), zerocols(n, false);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    zerorows[i] = true;
                    zerocols[j] = true;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(zerocols[j] || zerorows[i] ){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,1,1,5}};
    sol.setZeroes(matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}