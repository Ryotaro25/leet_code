class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    map<int, vector<int>> node_to_adjacents;
    for (auto edge : edges) {
      node_to_adjacents[edge[0]].push_back(edge[1]);
      node_to_adjacents[edge[1]].push_back(edge[0]);
    }

    map<int, int> node_to_parent;
    node_to_parent[0] = -1;

    set<int> visited;
    visited.insert(0);

    queue<int> traversing;
    traversing.push(0);
    while (!traversing.empty()) {
      int node = traversing.front();
      traversing.pop();

      for (int next_node : node_to_adjacents[node]) {
        // 次に向かおうとしているnodeが親ではないか
     
        if (node_to_parent[node] == next_node) {
          continue;
        }
        if (visited.contains(next_node)) {
          return false;
        }
        node_to_parent[next_node] = node;
        visited.insert(next_node);
        traversing.push(next_node);
      }
    }

    return visited.size() == n;
  }
};
