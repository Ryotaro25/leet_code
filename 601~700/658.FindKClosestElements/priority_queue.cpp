class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> distant_and_element;
    for (int i = 0; i < arr.size(); i++) {
      distant_and_element.push({abs(arr[i] - x), arr[i]});
      if (distant_and_element.size() > k) {
        distant_and_element.pop();
      }
    }

    vector<int> k_closest_elements;
    while (distant_and_element.size() > 0) {
      k_closest_elements.push_back(distant_and_element.top().second);
      distant_and_element.pop();
    }

    sort(k_closest_elements.begin(), k_closest_elements.end());

    return k_closest_elements;
  }
};
