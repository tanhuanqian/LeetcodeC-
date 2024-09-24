#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int minLength;
        for (const string& str : strs) {
            minLength = min(minLength, static_cast<int>(str.length()));
        }
        for(int i = 0; i < minLength; i++){
            char c = strs[0][i];
            for(const string& str : strs){
                if(str[i] != c){
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(strs);
    return 0;
}