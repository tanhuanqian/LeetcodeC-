#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    string haystack = "mississippi", needle = "issip";
    cout << sol.strStr(haystack, needle);
}