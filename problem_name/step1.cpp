class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    map<int, vector<int>> node_to_neighbors;
    for (auto edge : edges) {
      node_to_neighbors[edge[0]].push_back(edge[1]);
      node_to_neighbors[edge[1]].push_back(edge[0]);
    }

    set<int> visited;
    int num_component = 0;
    for (int i = 0; i < n; i++) {
      if (visited.contains(i)) {
        continue;
      }
      num_component++;
      TraverseNode(node_to_neighbors, visited, i);
    }
    return num_component;
  }

private:
  void TraverseNode(map<int, vector<int>>& node_to_neighbors, set<int>& visited, int node) {
    visited.insert(node);

    for (auto neighbor : node_to_neighbors[node]) {
      if (visited.contains(neighbor)) {
        continue;
      }
      TraverseNode(node_to_neighbors, visited, neighbor);
    }
  }
};
