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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
      return false;
    }
    if (IsIdentical(root, subRoot)) {
      return true;
    }
 
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool IsIdentical(TreeNode* node, TreeNode* other_node) {
    if (!node && !other_node) {
      return true;
    }
    if (!node || !other_node) {
      return false;
    }
    if (node->val != other_node->val) {
      return false;
    }
    return IsIdentical(node->left, other_node->left) && IsIdentical(node->right, other_node->right);
  }
};
