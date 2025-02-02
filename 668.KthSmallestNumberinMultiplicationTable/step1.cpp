class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int min_number = 1;
    int max_number = m * n;

    while (min_number < max_number) {
      int middle = min_number + (max_number - min_number) / 2;
      
      // middle以下の数がk個以上あるか確認
      // 範囲を狭めながらちょうどKに狭める
      if (IsKthNumber(m, n, k, middle)) {
        max_number = middle;
      } else {
        min_number = middle + 1;
      }
    }

    return min_number;
  }

private:
  bool IsKthNumber(int m, int n, int k, int middle) {
    int count = 0;
    for (int i = 1; i <= m; i++) {
      count += min(middle / i, n);
    }

    return count >= k;
  }
};
