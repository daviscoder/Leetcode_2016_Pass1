class Solution {
private:
    vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector <string> res, ret, part1;
        if (digits.size() == 0)
            return res;
        int current_digit = digits[0] - '0';
        for (int i = 0; i < table[current_digit].size(); i++) {
            string tmp = "";
            tmp += table[current_digit][i];
            part1.push_back (tmp);
        }
        digits.erase (digits.begin());
        ret = letterCombinations (digits);
        for (int i = 0; i < (int)part1.size(); i++) {
            for (int j = 0; j < (int)ret.size(); j++) {
                string t = part1[i];
                t += ret[j];
                res.push_back(t);
            }
            if (ret.size() == 0) {
                string t = part1[i];
                res.push_back (t);
            }
        }
        return res;
    }
};
