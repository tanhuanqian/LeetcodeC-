#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res = {""};
        for(int i=0; i<digits.length(); i++){
            string str = map[digits[i]-'0'];
            vector<string> t;
            for(int j=0; j<str.length(); j++){
                for(string s: res){
                    t.push_back(s+str[j]);
                }
            }
            res = t;
        }
        return res;

    }
    
};

int main() {
    Solution sol;
    string str = "23";
    vector<string> res = sol.letterCombinations(str);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}