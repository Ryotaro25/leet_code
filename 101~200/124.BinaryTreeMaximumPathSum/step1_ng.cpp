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

// ツリーのパスが必ずしもinorderになるとは限らない
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    if (!root) {
      return -1;
    }
    vector<int> nums;
    GetAllNums(nums, root);

    int max_sum = nums[0];
    vector<int> max_sums(nums.size());
    max_sums[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      max_sums[i] = max(max_sums[i - 1] + nums[i], nums[i]);
      max_sum = max(max_sum, max_sums[i]);
    }
    return max_sum;
  }

private:
  void GetAllNums(vector<int>&nums, TreeNode* node) {
    if (!node) {
      return;
    }
    GetAllNums(nums, node->left);
    nums.push_back(node->val);
    GetAllNums(nums, node->right);
  }
};