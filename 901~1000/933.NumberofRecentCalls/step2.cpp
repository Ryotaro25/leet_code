class RecentCounter {
public:
  RecentCounter() {
    
  }
  
  int ping(int t) {
    requested_times.push(t);
    while (requested_times.front() < t - 3000) {
      requested_times.pop();
    }
    return requested_times.size();
  }

private:
  queue<int> requested_times;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */