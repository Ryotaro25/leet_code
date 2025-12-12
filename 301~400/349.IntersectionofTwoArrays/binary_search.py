class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def binary_search(nums: List[int], target: int) -> bool:
            left = 0
            right = len(nums) - 1
            while left <= right:
                middle = (left + right) // 2
                if nums[middle] == target:
                    return True
                if nums[middle] < target:
                    left = middle + 1
                else:
                    right = middle - 1
            return False
 
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        nums2.sort()

        intersected_nums = set()
        for num in nums1:
            if binary_search(nums2, num):
                intersected_nums.add(num)
        return list(intersected_nums)
