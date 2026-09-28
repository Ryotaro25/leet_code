class KthLargest:

    def __init__(self, k: int, nums: list[int]):
        self.k = k
        self.sorted_nums = []
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        heapq.heappush(self.sorted_nums, val)
        if len(self.sorted_nums) > self.k:
            heapq.heappop(self.sorted_nums)
        return self.sorted_nums[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)