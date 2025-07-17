class MedianFinder {
public:
  MedianFinder() {
  
  }

  // Adds a number into the data structure.
  void addNum(int num) {
    max_heap.push(num);

    // balancing step
    min_heap.push(max_heap.top());
    max_heap.pop();

    // maintain size property
    if (max_heap.size() < min_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

    // Returns the median of current data stream
    double findMedian() {
      if (max_heap.size() > min_heap.size()) {
        return max_heap.top();
      }
      return (static_cast<double>(max_heap.top()) + static_cast<double>(min_heap.top())) / 2.0;
    }

private:
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */