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
    if (!root) {
      return {nullptr, nullptr};
    }

    if (root->val > target) {
      // 0がtarget以下、1がtargetより大きい
      auto nodes = splitBST(root->left, target);
      // 現在のrootは targetより大きいので1をroot側に繋ぐ
      root->left = nodes[1];
      return {nodes[0], root};
    } else {
      // 0がtarget以下、1がtargetより大きい
      auto nodes = splitBST(root->right, target);
      // 現在のrootは「target以下」なので0をroot側に繋ぐ
      root->right = nodes[0];
      return {root, nodes[1]};
    }

  }
};
