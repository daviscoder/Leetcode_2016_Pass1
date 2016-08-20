class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int furthest = 0, jmp = 0, last_jmp_limit = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + i > furthest)
                furthest = nums[i] + i;
            if (i == last_jmp_limit) {// has to add a jump here.
                jmp++;
                last_jmp_limit = furthest;
            }
        }
        return furthest >= nums.size() - 1? jmp : jmp + 1;
    }
};
