// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS, but time limit exceed
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};