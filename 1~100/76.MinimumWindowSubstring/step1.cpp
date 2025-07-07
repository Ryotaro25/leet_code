class Solution {
public:
  // TLE
  string minWindow(string s, string t) {
    map<char, int> letter_to_cnt;
    for (char letter : t) {
      letter_to_cnt[letter]++;
    }

    string min_window_substr = "";
    int min_window_size = numeric_limits<int>::max();
    for (int i = 0; i < s.size(); i++) {
      string current_substr;
      for (int j = i; j < s.size(); j++) {
        current_substr.push_back(s[j]);

        if (!IsIncluded(letter_to_cnt, current_substr)) {
          continue;
        }
        if (current_substr.size() < min_window_size) {
          min_window_substr = current_substr;
          min_window_size = current_substr.size();
        }
      }
    }

    return min_window_substr;
  }

private:
  bool IsIncluded(map<char, int> letter_to_cnt, const string& substr) {
    for (char letter : substr) {
      if (letter_to_cnt.contains(letter)) {
        letter_to_cnt[letter]--;
      }
    }

    for (auto [letter, cnt] : letter_to_cnt) {
      if (cnt > 0) {
        return false;
      }
    }
    return true;
  }
};
