#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int l, int r, string str, int n, vector<string>& s){
        if(l == n && r == n){
            s.push_back(str);
        }
        if(l < n){
            dfs(l+1, r, str + '(', n, s);
        }
        if(l > r){
            dfs(l, r+1, str + ')', n, s);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector <string> s;
        string str;
        dfs(0,0,str,n,s);
        return s;
    }
};

int main(){
    Solution sol;
    int n = 3;
    vector<string> s = sol.generateParenthesis(n);
    for(string str : s){
        cout << str << endl;
    }
    return 0;
}