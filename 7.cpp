#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);
        while (x > 0){
            int digit = x % 10;
            if (rev > (numeric_limits<long>::max() - digit) / 10) {
                return 0; 
            }
            rev = rev * 10 + digit;
            x /= 10;
        }
        rev *= sign;
        if(rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        return static_cast<int> (rev);
    }
};
int main() {
    Solution sol;
    int x = -2147483648;
    cout << sol.reverse(x) << endl;
    return 0;
}