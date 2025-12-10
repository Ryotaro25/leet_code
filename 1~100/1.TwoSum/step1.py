class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for index1, item1 in enumerate(nums):
            for index2, item2 in enumerate(nums):
                if index1 == index2:
                    continue
                if item1 + item2 == target:
                    return [index1, index2]
        return [-1, -1]
