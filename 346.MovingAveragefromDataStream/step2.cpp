class MovingAverage {
  public:
    MovingAverage(int size) {
      capacity = size;
    }
    
    double next(int val) {
      numbers.push_back(static_cast<int>(val));
      int nums_size = static_cast<int>(numbers.size());
 
      double sum = 0.0;
      int start_index = max(0, nums_size - capacity);
      for (int i = start_index; i < numbers.size(); i++) {
        sum += static_cast<double>(numbers[i]);
      }
      return sum / static_cast<double>(min(nums_size, capacity));
    }

  private:
    int capacity;
    vector<double> numbers;
  };
  /**
   * Your MovingAverage object will be instantiated and called as such:
   * MovingAverage* obj = new MovingAverage(size);
   * double param_1 = obj->next(val);
   */