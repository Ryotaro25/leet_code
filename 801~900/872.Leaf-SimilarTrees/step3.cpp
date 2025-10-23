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
    vector<int> leaf_values1;
    CreateLeafValues(root1, leaf_values1);
    vector<int> leaf_values2;
    CreateLeafValues(root2, leaf_values2);

    return leaf_values1 == leaf_values2;
  }

private:
  void CreateLeafValues(TreeNode* node, vector<int>& leaf_values) {
    if (!node) {
      return;
    }
    CreateLeafValues(node->left, leaf_values);
    if (!node->left && !node->right) {
      leaf_values.push_back(node->val);
    }
    CreateLeafValues(node->right, leaf_values);
  }
};
