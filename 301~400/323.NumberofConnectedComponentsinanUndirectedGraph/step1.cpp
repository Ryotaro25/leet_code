class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    map<int, vector<int>> node_to_adjacents;
    for (auto edge : edges) {
      node_to_adjacents[edge[0]].push_back(edge[1]);
      node_to_adjacents[edge[1]].push_back(edge[0]);
    }
    set<int> visited;
    int connected_component = 0;
    for (int node = 0; node < n; node++) {
      if (visited.contains(node)) {
        continue;
      }
      connected_component++;
      TraverseNode(node_to_adjacents, visited, node);
    }
    return connected_component;
  }

private:
  void TraverseNode(map<int, vector<int>>& node_to_adjacents, set<int>& visited, int node) {
    visited.insert(node);

    for (int next_node : node_to_adjacents[node]) {
      if (visited.contains(next_node)) {
        continue;
      }
      TraverseNode(node_to_adjacents, visited, next_node);
    }
  }
};
