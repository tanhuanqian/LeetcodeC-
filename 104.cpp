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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxpath(root);
        return res;
    }
    int maxpath(TreeNode* root){
        if(!root) return 0;
        int left  = maxpath(root->left);
        int right = maxpath(root->right);
        if(left  < 0) left  = 0;
        if(right < 0) right = 0;
        res = max(res, left+right+root->val);
        return root->val+max(left,right);
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
    vector<int> elements = {-10,9,20,NULL,NULL,15,7};
    TreeNode* root = buildTree(elements);
    cout << sol.maxPathSum(root);
    return 0;
}
