#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        vector<int> front(height.size(), 0), back(height.size(), 0);
        int n = height.size();
        int num = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            num = max(num, height[i]);
            front[i] = num;
        }
        num = 0;
        for (int i = n - 1; i >= 0; i--) {
            num = max(num, height[i]);
            back[i] = num;
        }
        for (int i = 0; i < n; i++) {
            sum += min(front[i], back[i]) - height[i];
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> height = {4,2,0,3,2,5};
    cout << sol.trap(height);
}

