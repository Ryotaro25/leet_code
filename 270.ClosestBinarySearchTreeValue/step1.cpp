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
    int closestValue(TreeNode* root, double target) {
      TreeNode* node = root;
      int closest_value = node->val;

      while (node) {
        if (abs(node->val - target) < abs(closest_value - target)) {
          closest_value = node->val;
        }
        if (abs(node->val - target) ==  abs(closest_value - target) && node->val < closest_value) {
          closest_value = node->val;
        }

        if (node->val > target) {
          node = node->left;
        } else {
          node = node->right;
        }
      }

      return closest_value;
    }
  };
