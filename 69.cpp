#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int root;
        while(left <= right) {
            root = left + (right - left) / 2;
            long long sqr = (long long)root * root;
            if (sqr == x) {
                return root;
            } else if (sqr > x) {
                right = root - 1;
                //cout << "right: " << right << " ";
            } else {
                left = root + 1;
                //cout << "left: " << left << " ";
            }
        }
        return right;
    }
};

int main(){
    Solution sol;
    int x = 8;
    cout << sol.mySqrt(x) << endl;
    return 0;
}