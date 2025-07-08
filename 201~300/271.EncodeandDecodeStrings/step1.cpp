class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string encoded = "";
    for (string str : strs) {
      int str_size = str.size();
      encoded += (to_string(str_size) + "#" + str);
    }
    return encoded;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> decoded;
    int i = 0;
    while (i < s.size()) {
      string str_size = "";
      while (i < s.size() && s[i] != '#') {
        str_size += s[i];
        i++;
      }
      if (i >= s.size()) {
        break;
      }
      // skip #
      i++;

      int target_length = std::stoi(str_size);
      string single_str = s.substr(i, target_length);
      decoded.push_back(single_str);
      i += target_length;
    }

    return decoded;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));