/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "n";
    }
    string serialized = to_string(root->val);
    serialized += "," + serialize(root->left);
    serialized += "," + serialize(root->right);
    return serialized;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<string> node_values;
    string segment;
    stringstream ss(data);
    while (getline(ss, segment, ',')) {
      cout << segment << endl;
      node_values.push_back(segment);
    }
    int index = 0;
    return Deserialize(node_values, index);
  }

private:
  TreeNode* Deserialize(vector<string>& node_values, int& index) {
    if (index >= node_values.size() || node_values[index] == "n") {
      if (index < node_values.size()) {
        index++;
      }
      return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(node_values[index]));
    index++;
    root->left = Deserialize(node_values, index);
    root->right = Deserialize(node_values, index);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));