#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, start = 0;
        for(int i = 0; i < gas.size(); i++){
            total = total + gas[i] - cost[i];
        }
        if (total < 0) return -1;
        total = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i]-cost[i];
            if(total < 0){
                start = i+1;
                total = 0;
            }
        }
        return start;
    }
};

int main(){
    Solution sol;
    vector<int> gas  = {3,1,1};
    vector<int> cost = {1,2,2};
    cout << sol.canCompleteCircuit(gas, cost);
    return 0;
}