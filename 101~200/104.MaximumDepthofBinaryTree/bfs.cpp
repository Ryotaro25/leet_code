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
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int max_depth = 0;
    queue<NodeAndLevel> node_and_level;
    node_and_level.emplace(root, 1);

    while (!node_and_level.empty()) {
      auto [node, level] = node_and_level.front();
      node_and_level.pop();

      max_depth = max(max_depth, level);

      if (node->left) {
        node_and_level.emplace(node->left, level + 1);
      }
      if (node->right) {
        node_and_level.emplace(node->right, level + 1);
      }
    }
    return max_depth;
  }

private:
  struct NodeAndLevel {
    TreeNode* node;
    int level;
  };
};
