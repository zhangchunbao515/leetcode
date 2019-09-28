class Solution {
 public:
  bool isValidBST(TreeNode* root) { return helper(root, NULL, NULL); }

 private:
  bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if (minNode && root->val <= minNode->val ||
        maxNode && root->val >= maxNode->val)
      return false;

    return helper(root->left, minNode, root) &&
           helper(root->right, root, maxNode);
  }
};