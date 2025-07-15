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
  int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder_nodes;
    InorderTraverse(root, inorder_nodes);
    return inorder_nodes[k - 1];
  }

private:
  void InorderTraverse(TreeNode* node, vector<int>& inorder_nodes) {
    if (!node) {
      return;
    }
    InorderTraverse(node->left, inorder_nodes);
    inorder_nodes.push_back(node->val);
    InorderTraverse(node->right, inorder_nodes);
  }
};
