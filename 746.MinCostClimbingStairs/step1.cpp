class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    if (cost.size() == 0) {
      return cost[0];
    }
    if (cost.size() == 2) {
      return min(cost[0], cost[1]);
    }

    vector<int> min_costs(cost.size());
    min_costs[0] = cost[0];
    min_costs[1] = cost[1];

    for (int i = 2; i < cost.size(); i++) {
      min_costs[i] = cost[i] + min(min_costs[i - 1], min_costs[i - 2]);
    }

    return min(min_costs[cost.size() - 2], min_costs[cost.size() - 1]);
  }
};
