#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (right+left)/2;
            if(target == nums[mid]){
                return mid;
            }
            if(nums[mid] >= nums[left]){
                if(target >= nums[left] && nums[mid] > target){
                    right = mid-1;
                } else{
                    left = mid+1;
                }
            } else{
                if(nums[right] >= target && nums[mid] < target){
                    left = mid+1;
                } else{
                    right = mid-1;
                }
            } 
            
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << sol.search(nums, target);
}