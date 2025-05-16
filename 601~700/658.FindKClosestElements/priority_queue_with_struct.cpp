class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<DistanceAndElement> distant_and_element;
    for (int i = 0; i < arr.size(); i++) {
      distant_and_element.push({abs(arr[i] - x), arr[i]});
      if (distant_and_element.size() > k) {
        distant_and_element.pop();
      }
    }

    vector<int> k_closest_elements;
    while (!distant_and_element.empty()) {
      k_closest_elements.push_back(distant_and_element.top().element);
      distant_and_element.pop();
    }

    sort(k_closest_elements.begin(), k_closest_elements.end());

    return k_closest_elements;
  }

private:
  struct DistanceAndElement {
    int distance;
    int element;

    bool operator<(const DistanceAndElement& other) const {
      if (distance == other.distance) {
        return element < other.element;
      }
      return distance < other.distance;
    }
  };
};
