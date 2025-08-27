/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> nodes;
    nodes.push(root);
    nodes.push(root);

    while (!nodes.empty()) {
      TreeNode* left = nodes.front();
      nodes.pop();
      TreeNode* right = nodes.front();
      nodes.pop();

      if (!left && !right) {
        continue;
      }
      if (!left || !right) {
        return false;
      }
      if (left->val != right->val) {
        return false;
      }
      nodes.push(left->left);
      nodes.push(right->right);
      nodes.push(left->right);
      nodes.push(right->left);
    }
    return true;
  }
};