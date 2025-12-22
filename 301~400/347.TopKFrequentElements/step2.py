class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_to_frequency = {}
        for num in nums:
            frequency = num_to_frequency.get(num, 0)
            num_to_frequency[num] = frequency + 1
        return sorted(num_to_frequency, key=lambda x:num_to_frequency[x], reverse=True)[:k]