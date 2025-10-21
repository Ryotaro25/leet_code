class RecentCounter {
public:
  RecentCounter() {
    
  }
  
  int ping(int t) {
    requested_times.push_back(t);
    int start = t - 3000;
    int end = t;
    int cnt = 0;
    for (int time : requested_times) {
      if (time >= start && time <= end) {
        cnt++;
      }
    }
    return cnt;
  }

private:
  vector<int> requested_times;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */