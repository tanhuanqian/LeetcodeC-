#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size()-1;
        while(mid <= right){
            if(nums[mid] == 1){
                mid++;
            } else if(nums[mid] == 0){
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            } else if(nums[mid] == 2){
                swap(nums[mid], nums[right]);
                mid++;
                right--;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> matrix = {2,0,2,1,1,0};
    sol.sortColors(matrix);
    for(int i = 0; i < matrix.size(); i++){
        cout << matrix[i] << " ";
    }
    return 0;
}