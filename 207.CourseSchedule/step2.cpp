class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, vector<int>> course_to_prerequisites;
    for (auto prerequisite : prerequisites) {
      course_to_prerequisites[prerequisite[0]].push_back(prerequisite[1]);
    }

    set<int> completed;
    set<int> pending;
    for (int course = 0; course < numCourses; course++) {
      if (!IsTakable(course, course_to_prerequisites, completed, pending)) {
        return false;
      }
    }
    return true;
  }

private:
  bool IsTakable(int course, map<int, vector<int>>& course_to_prerequisites,
                 set<int>& completed, set<int>& pending) {
    if (completed.contains(course)) {
      return true;
    }
    if (pending.contains(course)) {
      return false;
    }
    pending.insert(course);
    for (int prerequisite : course_to_prerequisites[course]) {
      if (!IsTakable(prerequisite, course_to_prerequisites, completed, pending)) {
        return false;
      }
    }
    pending.erase(course);
    completed.insert(course);
    return true;
  }
};
