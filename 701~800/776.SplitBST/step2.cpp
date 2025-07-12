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
  vector<TreeNode*> splitBST(TreeNode* node, int target) {
    TreeNode larger_root;
    TreeNode* larger_dummy = &larger_root;

    TreeNode smaller_root;
    TreeNode* smaller_dummy = &smaller_root;

    while (node) {
      if (node->val > target) {
        larger_dummy->left = node;
        larger_dummy = larger_dummy->left;
        node = node->left;
        larger_dummy->left = nullptr;
      } else {
        smaller_dummy->right = node;
        smaller_dummy = smaller_dummy->right;
        node = node->right;
        smaller_dummy->right = nullptr;
      }
    }

    return {smaller_root.right, larger_root.left};
  }
};