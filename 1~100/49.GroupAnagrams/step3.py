class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        common_key_to_words = {}
        for s in strs:
            common_key = str(sorted(s))
            key_to_word = common_key_to_words.setdefault(common_key, [])
            key_to_word.append(s)

        # return list(common_key_to_words.values())ともかける
        grouped_anagrams = []
        for _, words in common_key_to_words.items():
            grouped_anagrams.append(words)
        return grouped_anagrams 
