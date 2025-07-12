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
  vector<TreeNode*> splitBST(TreeNode* current_root, int target) {
    if (!current_root) {
      return {nullptr, nullptr};
    }
    if (current_root->val > target) {
      vector<TreeNode*> split_from_left = splitBST(current_root->left, target);
      current_root->left = split_from_left[1];
      return {split_from_left[0], current_root};
    } else {
      vector<TreeNode*> split_from_right = splitBST(current_root->right, target);
      current_root->right = split_from_right[0];
      return {current_root, split_from_right[1]};
    }
  }
};
