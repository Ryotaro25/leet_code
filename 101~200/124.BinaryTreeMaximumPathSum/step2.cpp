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
    GetMaxSum(root, max_sum);
    return max_sum;
  }

private:
  int GetMaxSum(TreeNode* node, int& max_sum) {
    if (!node) {
      return 0;
    }

    int left_max = max(GetMaxSum(node->left, max_sum), 0);
    int right_max = max(GetMaxSum(node->right, max_sum), 0);

    max_sum = max(max_sum, left_max + node->val + right_max);
    return max(left_max, right_max) + node->val;
  }
};
