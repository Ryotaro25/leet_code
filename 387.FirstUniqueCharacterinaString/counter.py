class Solution:
    def firstUniqChar(self, s: str) -> int:
        letter_to_cnt = collections.Counter(s)
        for i, letter in enumerate(s):
            if letter_to_cnt[letter] == 1:
                return i
        return -1
