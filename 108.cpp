#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        return midnode(nums, 0, nums.size()-1);
    }
    TreeNode* midnode(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(nums[start + (end-start)/2]);
        root->left  = midnode(nums,start, start+(end-start)/2-1);
        root->right = midnode(nums,start+(end-start)/2+1, end);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution sol;
    vector<int> elements1 = {-10,-3,0,5,9};
    TreeNode* root = sol.sortedArrayToBST(elements1);
    printTree(root);
    return 0;
}
