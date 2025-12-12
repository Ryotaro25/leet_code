class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i = 0
        j = 0
        unique_intersected_nums = set()
        nums1.sort()
        nums2.sort()
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                unique_intersected_nums.add(nums1[i])
                i += 1
                j += 1
                continue
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        
        intersected_nums = []
        for num in unique_intersected_nums:
            intersected_nums.append(num)
        return intersected_nums
