class MovingAverage {
  public:
    int capacity;
    int start_index;
    int end_index;
    vector<double> numbers;

    MovingAverage(int size) {
      capacity = size;
      start_index = 0;
      end_index = 0;
    }
    
    double next(int val) {
      numbers.push_back(static_cast<int>(val));
      if (numbers.size() > capacity) {
        start_index++;
        end_index++;
      } else {
        end_index++;
      }
      double sum = 0.0;
      for (int i = start_index; i < end_index; i++) {
        sum += numbers[i];
      }
      return sum / (end_index - start_index);
    }
  };
  /**
   * Your MovingAverage object will be instantiated and called as such:
   * MovingAverage* obj = new MovingAverage(size);
   * double param_1 = obj->next(val);
   */