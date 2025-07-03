class Solution {
public:
  // TLE
  int climbStairs(int n) {
    vector<int> visited(n + 1, NOTVISITED);
    return CalcWays(0, n, visited);
  }

private:
  static constexpr int NOTVISITED = -1;

  int CalcWays(int i, int num_steps, vector<int>& visited) {
    if (i > num_steps) {
      return 0;
    }
    if (i == num_steps) {
      return 1;
    }
    if (visited[i] != NOTVISITED) {
      return visited[i];
    }
    visited[i] = CalcWays(i + 1, num_steps, visited) + CalcWays(i + 2, num_steps, visited);
    return visited[i];
  }
};
