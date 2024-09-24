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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            for(int i = 0; i < len; i++){
                TreeNode* now = q.front();
                q.pop();
                if(now) temp.push_back(now->val);
                if(now->left) q.push(now->left);
                if(now->right)q.push(now->right);
            }
            res.push_back(temp);
        }
        return res;
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
    vector<int> elements = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = buildTree(elements);
    vector<vector<int>> matrix = sol.levelOrder(root);
    for(int i = 0; i < matrix[i].size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
