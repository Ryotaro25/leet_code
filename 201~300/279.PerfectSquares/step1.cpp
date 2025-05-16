class Solution {
  public:
    int numSquares(int n) {
      vector<int> squares;
      for (int i = 1; i <= sqrt(n); i++) {
        squares.push_back(i * i);
      }

      int least_squares = numeric_limits<int>::max();
      queue<RemaindAndNumSquare> candidates;
      candidates.push({n, 0});
      set<int> visited;
      while (!candidates.empty()) {
        auto candidate = candidates.front();
        candidates.pop();
        int remaind = candidate.remaind;
        int num_square = candidate.num_square;

        if (remaind == 0) {
          least_squares = min(num_square, least_squares);
        }
        for (int square : squares) {
          int next_remaind = remaind - square;
          if (next_remaind < 0) {
            continue;
          }
          if (visited.contains(next_remaind)) {
            continue;
          }
          candidates.push({next_remaind, num_square + 1});
          visited.insert(next_remaind);
        }
      }
      return least_squares;
    }
  
  private:
    struct RemaindAndNumSquare {
      int remaind;
      int num_square;
    };
  };
