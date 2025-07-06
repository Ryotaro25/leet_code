class Solution {
public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty()) {
      return "";
    }
    map<char, int> having_letter_to_cnt;
    int num_satisfied_letters = 0;

    map<char, int> required_letter_to_cnt;
    for (char letter : t) {
      required_letter_to_cnt[letter]++;
    }
    int num_unique_letters = required_letter_to_cnt.size();

    WindowBounds candidate = {-1, 0, 0};
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      having_letter_to_cnt[s[right]]++;
      if (required_letter_to_cnt.contains(s[right]) &&
          having_letter_to_cnt[s[right]] == required_letter_to_cnt[s[right]]) {
        num_satisfied_letters++;
      }

      while (left <= right && num_satisfied_letters == num_unique_letters) {
        if (candidate.window_size == -1 || right - left + 1 < candidate.window_size) {
          candidate.window_size = right - left + 1;
          candidate.left = left;
          candidate.right = right;
        }

        having_letter_to_cnt[s[left]]--;
        if (required_letter_to_cnt.contains(s[left]) && 
            having_letter_to_cnt[s[left]] < required_letter_to_cnt[s[left]]) {
          num_satisfied_letters--;
        }
        left++;
      }
    }

    if (candidate.window_size == -1) {
      return "";
    }
    return s.substr(candidate.left, candidate.right - candidate.left + 1);
  }

private:
  struct WindowBounds {
    int window_size;
    int left;
    int right;
  };
};
