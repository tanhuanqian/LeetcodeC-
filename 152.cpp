#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int i = 0 ; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                dp[i][j] = dp[i][j-1]*nums[j];
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << sol.maxProduct(nums);
    return 0;
}