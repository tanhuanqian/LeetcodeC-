#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - prices[i-1] > 0){
                sum = sum + prices[i] - prices[i-1];
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> elements = {7,1,5,3,6,4};
    cout <<  sol.maxProfit(elements);
    return 0;
}
