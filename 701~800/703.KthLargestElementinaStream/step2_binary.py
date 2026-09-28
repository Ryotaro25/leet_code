class KthLargest:

    def __init__(self, k: int, nums: list[int]):
        self.k = k
        self.sorted_nums = nums
        self.sorted_nums.sort()


    def _get_insert_position(self, val: int):
        left = 0
        right = len(self.sorted_nums)

        while left < right:
            mid = (left + right) // 2
            if self.sorted_nums[mid] < val:
                left = mid + 1
            else:
                right = mid
        return left


    def add(self, val: int) -> int:
        index = self._get_insert_position(val)
        self.sorted_nums.insert(index, val)
        return self.sorted_nums[-self.k]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)