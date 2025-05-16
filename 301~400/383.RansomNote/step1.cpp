class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    map<char, int> target_letters_to_cnt;
    for (auto letter : ransomNote) {
      target_letters_to_cnt[letter]++;
    }

    for (auto letter : magazine) {
      if (target_letters_to_cnt.contains(letter)) {
        target_letters_to_cnt[letter]--;
      }
    }

    bool is_constructed = true;
    for (auto [letter, cnt] : target_letters_to_cnt) {
      if (cnt > 0) {
        is_constructed = false;
      }
    }
    return is_constructed;
   }
};
