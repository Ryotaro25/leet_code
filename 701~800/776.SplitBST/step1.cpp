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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
      TreeNode large_root;
      TreeNode* large_dummy = &large_root;

      TreeNode small_root;
      TreeNode* small_dummy = &small_root;

      while (root) {
        if (root->val > target) {
          large_dummy->left = root;
          large_dummy = large_dummy->left;
          root = root->left;
          large_dummy->left = nullptr;
        } else {
          small_dummy->right = root;
          small_dummy = small_dummy->right;
          root = root->right;
          small_dummy->right = nullptr;
        }
      }

      return {small_root.right, large_root.left};
    }
};
