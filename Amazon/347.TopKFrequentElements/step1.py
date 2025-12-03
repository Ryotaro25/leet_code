class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_to_frequency = {}
        for num in nums:
            frequency = num_to_frequency.get(num, 0)
            num_to_frequency[num] = frequency + 1
        sorted_num_to_freq = dict(sorted(num_to_frequency.items(), key=lambda x:x[1], reverse=True))
        return list(sorted_num_to_freq.keys())[:k]