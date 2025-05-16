class Solution {
public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() / k < m) {
      return -1;
    }

    int min_bloom_day = 1;
    int max_bloom_day = 0;
    for (int day : bloomDay) {
      max_bloom_day = max(max_bloom_day, day);
    }

    while (min_bloom_day < max_bloom_day) {
      int mid_day = min_bloom_day + (max_bloom_day - min_bloom_day) / 2;
      if (CanFormBouquet(bloomDay, mid_day, m, k)) {
        max_bloom_day = mid_day;
      } else {
        min_bloom_day = mid_day + 1;
      }
    }

    return min_bloom_day;
  }

private:
  bool CanFormBouquet(vector<int>& bloom_day, int min_day, 
                      int required_bouquet, int adjacent_flowers) {
    int num_bouquet = 0;
    int flowers = 0;
    for (auto day : bloom_day) {
      if (day <= min_day) {
        flowers++;
      } else {
        flowers = 0;
      }

      if (flowers == adjacent_flowers) {
        num_bouquet++;
        flowers = 0;
      }
    }
    return num_bouquet >= required_bouquet;
  }
};
