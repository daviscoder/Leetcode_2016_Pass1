class Solution {
public:
    static bool comparator (string s1, string s2) {
        return s1 + s2 > s2 + s1? true : false;
    }
    string largestNumber(vector<int>& nums) {
        if ((int)nums.size() == 0) return "";
        vector<string> table;
        string res = "";
        for (int i = 0; i < nums.size(); i++)
            table.push_back (to_string(nums[i]));
        sort (table.begin(), table.end(), comparator);
        for (int i = 0; i < table.size(); i++)
            res += table[i];
        while (res.size() > 1 && res[0] == '0')
            res.erase (0, 1);
        return res;
    }
};
