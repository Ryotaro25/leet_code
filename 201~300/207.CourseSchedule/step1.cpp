class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, vector<int>> course_to_prerequisites;
    for (auto prerequisite : prerequisites) {
      course_to_prerequisites[prerequisite[0]].push_back(prerequisite[1]);
    }

    set<int> completed;
    set<int> active_courses;
    for (int i = 0; i < numCourses; i++) {
      if (!CheckCoursePrerequisites(i, course_to_prerequisites, completed, active_courses)) {
        return false;
      }
    }
    return true;
  }

private:
  bool CheckCoursePrerequisites(int course, map<int, vector<int>>& course_to_prerequisites,
                                set<int>& completed, set<int>& active_courses) {
    // prerequisite course has been finished
    if (completed.contains(course)) {
      return true;
    }
    // it has cycle
    if (active_courses.contains(course)) {
      return false;
    }
    
    active_courses.insert(course);
    for (auto prerequisite : course_to_prerequisites[course]) {
      if (!CheckCoursePrerequisites(prerequisite, course_to_prerequisites, completed, active_courses)) {
        return false;
      }
    }
    active_courses.erase(course);
    completed.insert(course);
    return true;
  }
};
