#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.count(c)) {
                char top_element = stk.empty() ? '#' : stk.top();
                stk.pop();
                if (top_element != mapping[c]) {
                    return false;
                }
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution sol;
    string s = "()[]{";
    cout << sol.isValid(s);
}