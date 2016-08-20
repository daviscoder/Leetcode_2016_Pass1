class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, int> my_map;
        for (int i = 0; i < (int) nums.size(); i++) {
            my_map[nums[i]]++;
            if (my_map[nums[i]] >= 2)
                return true;
        }
        return false;
    }
};
