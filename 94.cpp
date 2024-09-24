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
    void travel(vector<int>& ans, TreeNode* node){
        if (!node){
            ans.push_back(node->val);
            return;
        }
        if(node -> left){
            travel(ans, node->left);
        }
        ans.push_back(node->val);
        if(node->right){
            travel(ans, node->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        travel(ans, root);
        return ans;
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
    vector<int> elements = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
    TreeNode* root = buildTree(elements);
    printTree(root);
    cout << endl;
    vector<int> ans = sol.inorderTraversal(root);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
