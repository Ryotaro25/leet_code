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
    map<int, TreeNode*> val_to_node;
    TraverseTree(root, val_to_node);
    
    int cnt = 1;
    for (auto [val, node] : val_to_node) {
      if (cnt == k) {
        return node->val;
      }
      cnt++;
    }
    return -1;
  }

private:
  void TraverseTree(TreeNode* node, map<int, TreeNode*>& val_to_node) {
    if (!node) {
      return;
    }
    val_to_node[node->val] = node;
    TraverseTree(node->left, val_to_node);
    TraverseTree(node->right, val_to_node);
  }
};
