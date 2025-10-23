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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf_values_to_root1;
    CreateLeafValueSequence(root1, leaf_values_to_root1);
    vector<int> leaf_values_to_root2;
    CreateLeafValueSequence(root2, leaf_values_to_root2);

    return leaf_values_to_root1 == leaf_values_to_root2;
  }

private:
  void CreateLeafValueSequence(TreeNode* node, vector<int>& leaf_values) {
    if (!node) {
      return;
    }
    CreateLeafValueSequence(node->left, leaf_values);
    if (!node->left && !node->right) {
      leaf_values.push_back(node->val);
    }
    CreateLeafValueSequence(node->right, leaf_values);
  }
};
