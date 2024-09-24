#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                return false;
            }
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                return true;
            }
            cout << farthest;
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,1,0,4};
    cout << sol.canJump(nums);
}