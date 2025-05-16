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
    vector<int> inordered_nodes;
    GenerateNodesValues(inordered_nodes, root);
    return inordered_nodes;
  }

private:
  void GenerateNodesValues(vector<int>& inordered_nodes, TreeNode* node) {
    if (!node) {
      return;
    }
    GenerateNodesValues(inordered_nodes, node->left);
    inordered_nodes.push_back(node->val);
    GenerateNodesValues(inordered_nodes, node->right);
  }
};
