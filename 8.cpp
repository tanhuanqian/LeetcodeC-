#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        long long sum = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int temp = s[i] - '0';
            if (sum > (numeric_limits<long long>::max() - temp) / 10) {
                return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            sum = sum * 10 + temp;
            i++;
        }
        sum *= sign;
        if (sum < numeric_limits<int>::min()) {
            return numeric_limits<int>::min();
        }
        if (sum > numeric_limits<int>::max()) {
            return numeric_limits<int>::max();
        }

        return static_cast<int>(sum);
    }
};

int main() {
    Solution sol;
    string x = "-91283472332";
    cout << sol.myAtoi(x) << endl;
    return 0;
}
