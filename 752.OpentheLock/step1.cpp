class Solution {
  public:
    int openLock(vector<string>& deadends, string target) {
      if (IsDead(deadends, "0000")) {
        return -1;
      }
      queue<KeyAndNumRotate> candidates;
      candidates.push({"0000", 0});

      set<string> visited;
      visited.insert("0000");

      while (!candidates.empty()) {
        KeyAndNumRotate candidate = candidates.front();
        candidates.pop();
        string open_key = candidate.key;
        int num_rotate = candidate.num_rotate;

        if (open_key == target) {
          return num_rotate;
        }
        for (int i = 0; i < open_key.size(); i++) {
          for (int direction = -1; direction <= 1; direction += 2) {
            string cloned = open_key;
            cloned[i] = '0' + ((cloned[i] - '0' + direction + 10) % 10);
            int next_num_rotate = num_rotate + 1;
  
            if (visited.contains(cloned)) {
              continue;
            }
  
            if (IsDead(deadends, cloned)) {
              continue;
            }
            candidates.push({cloned, next_num_rotate});
            visited.insert(cloned);
          }
        }
      }
      return -1;
    }
  
  private:
    struct KeyAndNumRotate {
      string key;
      int num_rotate;
    };

    bool IsDead(vector<string>& deadends, string target_key) {
      for (const auto deadend : deadends) {
        if (target_key == deadend) {
          return true;
        }
      }
      return false;
    }
  };
