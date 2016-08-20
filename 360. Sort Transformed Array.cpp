class Solution {
public:

    int compute (int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector <int> res (nums.size(), 0);
        int i = 0, j = nums.size() - 1, index = a >= 0? nums.size() - 1 : 0;
        while (i <= j) {
            int i_val = compute (nums[i], a, b, c);
            int j_val = compute (nums[j], a, b, c);
            if (a >= 0) {
                if (i_val > j_val) {
                    res[index--] = i_val;
                    i++;
                }
                else {
                    res[index--] = j_val;
                    j--;
                }
            }
            else {
                if (i_val < j_val) {
                    res[index++] = i_val;
                    i++;
                }
                else {
                    res[index++] = j_val;
                    j--;
                }
            }
        }
        return res;
    }
};
