class Solution {
public:
  // TLE
  string minWindow(string s, string t) {
    map<char, int> letter_to_cnt;
    for (char letter : t) {
      letter_to_cnt[letter]++;
    }

    string min_window_substr = "";
    string current_substr = "";
    int min_window_size = numeric_limits<int>::max();
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      current_substr.push_back(s[right]);

      while (left < s.size() && !IsIncluded(letter_to_cnt, current_substr)) {
        current_substr.erase(current_substr.begin());
        left++;
      }

      if (current_substr.size() < min_window_size) {
        min_window_substr = current_substr;
        min_window_size = current_substr.size();
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

    int cover_cnt = 0;
    for (auto [letter, cnt] : letter_to_cnt) {
      if (cnt > 0) {
        return false;
      }
    }
    return true;
  }
};
