#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bot = matrix.size()-1, top = 0;
        int right = matrix[0].size()-1, left = 0;
        vector<int> res;
        while(top <= bot && left <= right){
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
                //cout << matrix[top][i] << " a";
            }
            top++;
            for(int i = top; i <= bot; i++){
                res.push_back(matrix[i][right]);
                //cout << matrix[i][right] << " b";
            }
            right--;
            if(top <= bot){
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bot][i]);
                    //cout << matrix[bot][i] << " c";
                }
                bot--;
            }
            if(left <= right){
                for(int i = bot; i >= top; i--){
                    res.push_back(matrix[i][left]);
                    //cout << matrix[i][left] << " d";
                }
                left++;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = sol.spiralOrder(matrix);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]<< " ";
    }
    return 0;
}