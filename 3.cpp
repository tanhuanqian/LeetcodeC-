#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) > 0 && charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }
            charMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
