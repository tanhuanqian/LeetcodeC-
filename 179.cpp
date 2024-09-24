#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int num : nums) {
            str_nums.push_back(to_string(num));
        }
        sort(str_nums.begin(), str_nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        if (str_nums[0] == "0") return "0";
        string result;
        for (string &s : str_nums) {
            result += s;
        }

        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,30,34,5,9};
    cout << sol.largestNumber(nums);
    return 0;
}