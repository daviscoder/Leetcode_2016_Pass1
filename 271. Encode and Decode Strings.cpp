class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs.size(); i++)
            res += to_string (strs[i].size()) + "#" + strs[i];
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while (s.empty() == false) {
            int pos = s.find_first_of ('#');
            int length = stoi (s.substr (0, pos));
            res.push_back (s.substr (pos + 1, length));
            s = s.substr (pos + 1 + length);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
