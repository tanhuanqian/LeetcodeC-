#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;

        for (int i = 2; i <= n; i++) {
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigits = stoi(s.substr(i-2, 2));

            if (oneDigit >= 1) dp[i] += dp[i-1];
            if (twoDigits >= 10 && twoDigits <= 26) dp[i] += dp[i-2];
            cout << oneDigit << " " << twoDigits << endl;
        }
        for(int i = 0; i < dp.size(); i++){
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    string s = "226";
    cout << sol.numDecodings(s);
    return 0;
}