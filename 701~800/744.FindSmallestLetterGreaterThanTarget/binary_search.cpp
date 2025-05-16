class Solution {
  public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int left = 0;
      int right = letters.size() - 1;

      while (left <= right) {
        int middle = left + (right - left) / 2;

        if (letters[middle] <= target) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }

      if (left == letters.size()) {
        return letters[0];
      }
      return letters[left];
    }
  };
  