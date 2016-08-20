class Solution {
public:
    unordered_set <int> mySet;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;
        for (int i = 0; i < nums.size(); i++) {
            if (mySet.count (nums[i]))
                return true;
            if (mySet.size() >= k)
                mySet.erase (nums[i - k]);
            mySet.insert (nums[i]);
        }
        return false;
    }
};
