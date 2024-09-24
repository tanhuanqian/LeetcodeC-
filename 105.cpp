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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inorderMap[rootVal];
        int leftTreeSize = inRoot - inStart;

        root->left = helper(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, inRoot - 1, inorderMap);
        root->right = helper(preorder, preStart + leftTreeSize + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);

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
    vector<int> elements1 = {3,9,20,15,7};
    vector<int> elements2 = {9,3,15,20,7};
    TreeNode* root = sol.buildTree(elements1, elements2);
    printTree(root);
    return 0;
}
