class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.size() == 1) {
      if (flowerbed[0] == 0) {
        return n <= 1;
      } else {
        return n <= 0;
      }
    }

    int cnt = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 1) {
        continue;
      }
      if (i == 0) {
        if (flowerbed[i + 1] == 0) {
          cnt++;
          flowerbed[i] = 1;
        }
        continue;
      }

      if (i == flowerbed.size() -  1) {
        if (flowerbed[i - 1] == 0) {
          cnt++;
          flowerbed[i] = 1;
        }
        continue;
      }

      if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
        cnt++;
        flowerbed[i] = 1;
      }
    }
    return cnt >= n;
  }
};
