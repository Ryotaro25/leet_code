class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int min_eating_speed = 1;
    int max_eating_speed = 0;
    for (auto pile : piles) {
      max_eating_speed = max(max_eating_speed, pile);
    }

    while (min_eating_speed < max_eating_speed) {
      int middle = min_eating_speed + (max_eating_speed - min_eating_speed) / 2;

      if (IsEatable(piles, middle, h)) {
        max_eating_speed = middle;
      } else {
        min_eating_speed = middle + 1;
      }
    }

    return min_eating_speed;
  }

private:
  bool IsEatable(vector<int>& piles, int eating_speed, int limit_hours) {
    int total_hours = 0;

    for (auto pile : piles) {
      // 切り上げる必要がある
      total_hours += (pile + eating_speed - 1) / eating_speed;
    }

    return total_hours <= limit_hours;
  }
};
