class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.capacity = k
        self.top_k_nums = []
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        heappush(self.top_k_nums, val)
        if len(self.top_k_nums) > self.capacity:
            heappop(self.top_k_nums)
        return self.top_k_nums[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)