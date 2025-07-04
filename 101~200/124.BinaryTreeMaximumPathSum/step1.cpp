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
  int maxPathSum(TreeNode* root) {
    int max_sum = root->val;
    GainMaxSum(root, max_sum);
    return max_sum;
  }

private:
  int GainMaxSum(TreeNode* node, int& max_sum) {
    if (!node) {
      return 0;
    }

    int left_subtree_max = max(0, GainMaxSum(node->left, max_sum));
    int right_subtree_max = max(0, GainMaxSum(node->right, max_sum));

    max_sum = max(max_sum, left_subtree_max + node->val + right_subtree_max);
    return max(left_subtree_max, right_subtree_max) + node->val;
  }
};
