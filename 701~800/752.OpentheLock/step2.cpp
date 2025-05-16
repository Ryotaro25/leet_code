class Solution {
  public:
    int openLock(vector<string>& deadends, string target) {
      set<string> visited(deadends.begin(), deadends.end());
      if (visited.contains("0000")) {
        return -1;
      }

      queue<KeyAndNumRotate> combinations;
      combinations.push({"0000", 0});

      vector<int> directions = {-1, 1};
      int num_rotate = 0;

      while (!combinations.empty()) {
        KeyAndNumRotate candidate = combinations.front();
        combinations.pop();
        string candidate_key = candidate.key;
        int num_rotate = candidate.num_rotate;

        if (candidate_key == target) {
          return num_rotate;
        }

        for (int i = 0; i < candidate_key.size(); i++) {
          for (int direction : directions) {
            string cloned = candidate_key;
            cloned[i] = '0' + ((cloned[i] - '0' + direction + 10) % 10);
            if (visited.contains(cloned)) {
              continue;
            }
            combinations.push({cloned, num_rotate + 1});
            visited.insert(cloned);
          }
        }
      }
      // 解除できない場合
      return -1;
    }

    private:
      struct KeyAndNumRotate {
        string key;
        int num_rotate;
      };
  };
