#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            if(i > 0 and nums[i] == nums[i-1]){
                continue;
            }
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                cout << sum << endl;
                if(sum > 0){
                    k--;
                } else if (sum < 0){
                    j++;
                } else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    j++;
                    while(nums[j] == nums[j-1] && j < k){
                        j++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = sol.threeSum(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < 3; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}