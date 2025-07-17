// TLE
class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
      if (nums.empty()) {
        nums.push_back(num);
        return;
      }

      auto position = lower_bound(nums.begin(), nums.end(), num);
      nums.insert(position, num);
    }
    
    double findMedian() {
      double median = 0.0;
      int size = nums.size();
      if (size == 1) {
        median = static_cast<double>(nums[0]);
      } else if (size % 2 == 0) {
        median = (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
      } else {
        median = static_cast<double>(nums[size / 2]);
      }
      return median;
    }

private:
  vector<int> nums;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */