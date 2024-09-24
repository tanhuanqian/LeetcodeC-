#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxwater = 0;
        while (i < j){
            int maxi = min(height[i], height[j]);
            int water = maxi * (j-i);
            maxwater = max(water, maxwater);
            if(height[i] > height[j]){
                j--;
            } else{
                i++;
            }
        }
        return maxwater;
    }
};

int main(){
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height);
    return 0;
}