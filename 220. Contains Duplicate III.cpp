class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0 || nums.size() <= 1) return false;
        map <int, int> myMap;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - j > k && myMap[nums[j]] == j) {
                myMap.erase (nums[j]);
                j++;
            }
            auto it = myMap.lower_bound (nums[i] - t);
            if (it != myMap.end() && abs (it->first - nums[i]) <= t)
                return true;
            myMap[nums[i]] = i;
        }
        return false;
    }
};
