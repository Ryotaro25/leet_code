class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        common_key_to_words = {}
        for word in strs:
            commom_key = str(sorted(word))
            word_to_str = common_key_to_words.setdefault(commom_key, [])
            word_to_str.append(word)
        
        anagrams = []
        for _, words in common_key_to_words.items():
            anagrams.append(words)
        return anagrams
