class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> table ({{'1', '1'}, {'0', '0'}, {'8', '8'}, {'6', '9'}, {'9', '6'}});
        int i = 0, j = num.size() - 1;
        while (i <= j) {
            if (table[num[i]] != num[j] || table[num[j]] != num[i])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
