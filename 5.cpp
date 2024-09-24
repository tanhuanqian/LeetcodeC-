#include<string>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int expand(string s, int l, int r){
        while(l >= 0 && r <= s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;

        for(int i = 0; i < n; i++){
            int len1 = expand(s,i,i);
            int len2 = expand(s,i,i+1);
            int maxlen = max(len1, len2);

            if (maxlen > end - start){
                start = i - (maxlen-1)/2;
                end = i + maxlen/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
int main() {
    Solution sol;
    string s = "cbbd";

    cout << "Median: " << sol.longestPalindrome(s) << endl;
    return 0;
}