class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (right - left + 1 > k) {
      // 右側の方が x に近い、または同じ距離なら右側を削除
      // 右側の方が x から遠いなら右側を削除
      if (abs(arr[left] - x) <= abs(arr[right] - x)) {
        right--;
      } else {
        left++;
      }
    }

    vector<int> k_closest_elements;
    for (int i = left; i <= right; i++) {
      k_closest_elements.push_back(arr[i]);
    }

    return k_closest_elements;
  }
};
