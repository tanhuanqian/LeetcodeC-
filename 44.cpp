#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        int i = 0, j = 0;
        int starIdx = -1, matchIdx = -1;

        while (i < n) {
            cout << s[i] << " " << p[j] << j << i << endl;
            if (j < m && (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            }
            else if (j < m && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++;
            }
            else if (starIdx != -1) {
                j = starIdx + 1;
                matchIdx++;
                i = matchIdx;
                cout << " a";
            }
            else {
                return false;
            }
        }
        while (j < m && p[j] == '*') {
            j++;
        }
        return j == m;
    }
};

int main() {
    Solution sol;
    string s = "acdcb", p = "a*cb";
    cout << sol.isMatch(s, p);
}

