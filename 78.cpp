#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);
        
        for (int i = start; i < nums.size(); i++) {
            currentSubset.push_back(nums[i]);
            backtrack(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> matrix = sol.subsets(nums);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}