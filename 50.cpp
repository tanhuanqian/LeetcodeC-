#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double ans = 1.0;
        long absn = abs(static_cast<long>(n));
        while(absn > 0){
            if(absn % 2 == 1){
                ans *= x;
            }
            x *= x;
            absn /= 2;
        }
        return (n < 0) ? 1/ans : ans;
    }
};

int main(){
    Solution sol;
    double x = 2.10000;
    int n = 3;
    cout << sol.myPow(x,n);
    return 0;
}