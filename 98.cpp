#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(const vector<int>& elements) {
    if (elements.empty() || elements[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(elements[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < elements.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < elements.size() && elements[i] != -1) {
            current->left = new TreeNode(elements[i]);
            q.push(current->left);
        }
        i++;
        if (i < elements.size() && elements[i] != -1) {
            current->right = new TreeNode(elements[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    bool check(TreeNode* node, long long lower, long long upper) {
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;
        
        return check(node->left, lower, node->val) && check(node->right, node->val, upper);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
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
    vector<int> elements = {5,4,6,NULL,NULL,3,7};
    TreeNode* root = buildTree(elements);
    cout << sol.isValidBST(root);
    return 0;
}
