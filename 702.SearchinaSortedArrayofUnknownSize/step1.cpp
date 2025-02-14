/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

 class Solution {
  public:
    int search(const ArrayReader& reader, int target) {
      int left = 0;
      int right = 1;
      while (reader.get(right) < target) {
        left = right;
        right *= 2;
      }

      while (left <= right) {
        int middle = left + (right - left) / 2;
        int num = reader.get(middle);

        if (num == target) {
          return middle;
        }

        if (num < target) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }

      return -1;
    }
  };
