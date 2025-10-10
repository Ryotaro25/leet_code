class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.size() == 1) {
      if (flowerbed[0] == 1) {
        return n == 0;
      } else {
        return n <= 1;
      }
    }

    vector<int> cloned_flowerbed = flowerbed;
    int cnt = 0;
    for (int i = 0; i < cloned_flowerbed.size(); i++) {
      if (cloned_flowerbed[i] == 1) {
        continue;
      }
      if (i == 0 && cloned_flowerbed[i + 1] != 1) {
        cloned_flowerbed[i] = 1;
        cnt += 1;
        continue;
      }
      if (i == cloned_flowerbed.size() - 1 && cloned_flowerbed[i - 1] != 1) {
        cloned_flowerbed[i] = 1;
        cnt += 1;
        break;
      }
      if (i != cloned_flowerbed.size() - 1 && cloned_flowerbed[i + 1] != 1 && cloned_flowerbed[i - 1] != 1) {
        cloned_flowerbed[i] = 1;
        cnt += 1;
      }
    }

    return cnt >= n;
  }
};
