class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string encoded = "";
    for (const string& str : strs) {
      int str_length = str.size();
      encoded += to_string(str_length);
      encoded += "#";
      encoded += str;
    }
    return encoded;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> decoded;
    int i = 0;
    while (i < s.size()) {
      int delimiter_position = s.find('#', i);
      string str_length = s.substr(i, delimiter_position - i);
      int length = stoi(str_length);

      int str_start_position = delimiter_position + 1;

      decoded.push_back(s.substr(str_start_position, length));
      i = str_start_position + length;
    }

    return decoded;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));