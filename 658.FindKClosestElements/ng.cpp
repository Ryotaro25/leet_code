// セットに距離を入れておいても
// [1,1,2,2,2,2,2,3,3]　k =3 x=3
// のようなものが来た場合に 2 2 2と返却してしまう

// chatgptより
// 距離を格納する set<int> k_differences を使って、
// 最小の k 個を選択しようとしていますが、これは 重複する距離の値が
//  k 個未満でも set に入れられない場合がある という問題を引き起こします。
// （set は一意な値のみ格納できるため）
class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      vector<int> differences;
      for (int i = 0; i < arr.size(); i++) {
        differences.push_back(abs(arr[i] - x));
      }

      sort(differences.begin(), differences.end());
      set<int> k_differences;
      int cnt = 1;
      for (int i = 0; i < differences.size(); i++) {
        if (cnt > k) {
          break;
        }
        k_differences.insert(differences[i]);
        cnt++;
      }

      vector<int> k_closest_element;
      for (int i = 0; i < arr.size(); i++) {
        if (k_closest_element.size() >= k) {
          break;
        }
        if (k_differences.contains(abs(arr[i] - x))) {
          k_closest_element.push_back(arr[i]);
        }
      }

      return k_closest_element;
    }
  };
