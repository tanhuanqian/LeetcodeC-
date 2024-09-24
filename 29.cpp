#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long quotient;
        if (dividend <= INT_MIN && divisor == -1){
            return INT_MAX;
        }
        quotient = dividend/divisor;
        return quotient;
    }
};

int main(){
    Solution sol;
    int dividend = -2147483648, divisor = -1;
    cout << sol.divide(dividend, divisor);
}