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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }

    vector<int> inordered_vals;
    stack<TreeNode*> inordered_nodes;
    TreeNode* node = root;
    while (node || !inordered_nodes.empty()) {
      while (node) {
        inordered_nodes.push(node);
        node = node->left;
      }

      node = inordered_nodes.top();
      inordered_nodes.pop();
      inordered_vals.push_back(node->val);
      node = node->right;
    }

    return inordered_vals;
  }
};
