class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) {
    kth_num = k;
    for (int num : nums) {
      add(num);
    }
  }
  
  int add(int val) {
    num_to_frequency[val]++;
    int size = 0;
    for (auto it = num_to_frequency.rbegin(); it != num_to_frequency.rend(); it++) {
      const auto& [val, frequency] = *it;
      size += frequency;
      if (size >= kth_num) {
        return val;
      }
    }
    return -1;
  }

private:
  int kth_num;
  map<int, int> num_to_frequency;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */