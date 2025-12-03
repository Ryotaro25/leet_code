class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_to_freq = {}
        for num in nums:
            frequency = num_to_freq.get(num, 0)
            num_to_freq[num] = frequency + 1
        return sorted(num_to_freq, key=lambda x:num_to_freq[x], reverse=True)[:k]