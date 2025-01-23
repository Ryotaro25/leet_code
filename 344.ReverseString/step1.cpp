class Solution {
public:
  void reverseString(vector<char>& s) {
    int index = 0;
    int reverse_index = s.size() - 1;
    
    while (index < reverse_index) {
      swap(s[index], s[reverse_index]);
      index++;
      reverse_index--;
    }
  }
};
