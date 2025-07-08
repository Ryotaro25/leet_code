class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    if (n == 0) {
      return 0;
    }
    vector<vector<int>> adjacent_nodes(n);
    for (auto edge : edges) {
      adjacent_nodes[edge[0]].push_back(edge[1]);
      adjacent_nodes[edge[1]].push_back(edge[0]);
    }

    int num_components = 0;
    set<int> visited;
    for (int node = 0; node < n; node++) {
      if (visited.contains(node)) {
        continue;
      }
      num_components++;
      TraverseNode(adjacent_nodes, visited, node);
    }
    return num_components;
  }

private:
  void TraverseNode(vector<vector<int>>& adjacent_nodes, set<int>& visited, int node) {
    visited.insert(node);

    for (int next_node : adjacent_nodes[node]) {
      if (visited.contains(next_node)) {
        continue;
      }
      TraverseNode(adjacent_nodes, visited, next_node);
    }
  }
};
