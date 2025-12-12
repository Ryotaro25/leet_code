class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        i = 0
        j = 0
        intersected_nums = set()
        nums1.sort()
        nums2.sort()
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                intersected_nums.add(nums1[i])
                i += 1
                j += 1
                continue
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        
        return list(intersected_nums)
