class Solution {
public:
  int compress(vector<char>& chars) {
    string compressed_str;
    for (int i = 0; i < chars.size(); i++) {
      char letter = chars[i];
      int cnt = 0;
      int j = i;
      while (j < chars.size() && chars[j] == letter) {
        cnt++;
        j++;
      }
      cout <<"index: " << i << " letter: " <<  letter << endl;

      compressed_str += letter;
      if (cnt != 1) {
        compressed_str += to_string(cnt);
      }
      i = j - 1;
    }
    cout << compressed_str << endl;

    return compressed_str.size();
  }
};
