class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {

    vector<vector<int>> common_letter_sizes(text1.size(), vector<int>(text2.size()));
    for (int i = 0; i < text1.size(); i++) {
      for (int j = 0; j < text2.size(); j++) {
        if (text1[i] != text2[j]) {
          if (i != 0) {
            common_letter_sizes[i][j] = max(common_letter_sizes[i][j],
                                            common_letter_sizes[i - 1][j]);
          }
          if (j != 0) {
            common_letter_sizes[i][j] = max(common_letter_sizes[i][j],
                                            common_letter_sizes[i][j - 1]);
          }
          continue;
        }

        if (i == 0 || j == 0) {
          common_letter_sizes[i][j] = 1;
        } else {
          common_letter_sizes[i][j] = common_letter_sizes[i - 1][j - 1] + 1;
        }
      }
    }

    return common_letter_sizes[text1.size() - 1][text2.size() - 1];
  }
};
