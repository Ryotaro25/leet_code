class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - k;

    while (left < right) {
      int middle = left + (right - left) / 2;
      // middle より middle + k の方が x に近いか
      if (x - arr[middle] > arr[middle + k] - x) {
        // arr[middle] は最適な k 個の要素に含まれない
        left = middle + 1;
      } else {
        // middle + k の方が遠いので、探索範囲を左に寄せる
        right = middle;
      }
    }

    vector<int> k_closest_elements;
    for (int i = left; i < left + k; i++) {
      k_closest_elements.push_back(arr[i]);
    }

    return k_closest_elements;
  }
};
