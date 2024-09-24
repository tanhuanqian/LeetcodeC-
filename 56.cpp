#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int intervalleft = intervals[0][0], intervalright = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervalright >= intervals[i][0]){
                intervalright = max(intervals[i][1], intervalright);
            } else{
                res.push_back({intervalleft, intervalright});
                intervalleft = intervals[i][0];
                intervalright = intervals[i][1];
            }
            cout << intervalleft << " " << intervalright << endl;
        }
        res.push_back({intervalleft, intervalright});
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,4},{0,6}};
    vector<vector<int>> res = sol.merge(nums);
    for(int i = 0; i < res.size(); i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    
}