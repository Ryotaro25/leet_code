class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        word_to_strs = {}
        for word in strs:
            sorted_word = str(sorted(word))
            word_to_str = word_to_strs.setdefault(sorted_word, [])
            word_to_str.append(word)
        
        grouped_words = []
        for word, strs in word_to_strs.items():
            anagrams = []
            for anagram in strs:
                anagrams.append(anagram)
            grouped_words.append(anagrams)
        return grouped_words

