class Solution:
    def firstUniqChar(self, s: str) -> int:
        letter_to_cnt = {}
        for c in s:
            cnt = letter_to_cnt.get(c, 0)
            letter_to_cnt[c] = cnt + 1

        for i, letter in enumerate(s):
            if letter_to_cnt[letter] == 1:
                return i
        return -1
