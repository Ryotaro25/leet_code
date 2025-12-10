class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_index = {}
        for index, item in enumerate(nums):
            num_to_index[item] = index
        for index, item in enumerate(nums):
            compliment = target - item
            if compliment in num_to_index and num_to_index[compliment] != index:
                return [num_to_index[compliment], index]
        return []
