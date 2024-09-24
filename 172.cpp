#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0){
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int n = 25;
    cout << sol.trailingZeroes(n);
    return 0;
}