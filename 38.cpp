#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result = "";
        int count = 1;
        
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }   
        result += to_string(count) + prev.back();
        return result;
    }
};

int main(){
    Solution sol;
    int n = 5;
    string s = sol.countAndSay(n);
    cout << s;
}