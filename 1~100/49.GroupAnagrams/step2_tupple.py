class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        common_key_to_words = {}
        for word in strs:
            commom_key = tuple(sorted(word))
            key_to_word = common_key_to_words.setdefault(commom_key, [])
            key_to_word.append(word)
        
        anagrams = []
        for _, words in common_key_to_words.items():
            anagrams.append(words)
        return anagrams
