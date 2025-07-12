class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> result;
        int start = 0;
        int bsStart = 0;
        int n = products.size();
        string prefix;

        for (char &c : searchWord) {
            prefix += c;

            // Get the starting index of word starting with `prefix`.
            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

            // Add empty vector to result.
            result.push_back({});

            // Add the words with the same prefix to the result.
            for (int i = start; i < min(start + 3, n); i++) {
                // products[i] の先頭が prefix と一致するかをチェック
                if (products[i].find(prefix) != 0) {
                  break;
                }
                result.back().push_back(products[i]);
            }

            // Reduce the size of elements to binary search on since we know
            bsStart = start;
        }
        return result;
    }
};