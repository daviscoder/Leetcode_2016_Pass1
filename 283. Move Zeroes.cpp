class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int p = 0, q = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                while (nums[p] == 0 && p < nums.size())
                    p++;
                if (p < nums.size()) {
                    int tmp = nums[p];
                    nums[p] = nums[i];
                    nums[i] = tmp;
                }
            }
            else {
                p = i + 1;
            }
        }
    }
};


------ Better Solution

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cnt++;
            else {
                int tmp = nums[i];
                nums[i] = 0;
                nums[i - cnt] = tmp;
            }
        }
    }
};

