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
    TreeNode* node = FindRoot(root, subRoot->val);
    return IsIdentical(node, subRoot);
  }

private:
  TreeNode* FindRoot(TreeNode* node, int target) {
    if (!node) {
      return nullptr;
    }
    if (node->val == target) {
      return node;
    }
    TreeNode* left_node = FindRoot(node->left, target);
    if (left_node) {
      return left_node;
    }

    return FindRoot(node->right, target);;
  }

  bool IsIdentical(TreeNode* node, TreeNode* subRoot) {
    if (!node && !subRoot) {
      return true;
    }
    if (!node || !subRoot) {
      return false;
    }
    if (node->val != subRoot->val) {
      return false;
    }
    return IsIdentical(node->left, subRoot->left) && IsIdentical(node->right, subRoot->right);
  }
};
