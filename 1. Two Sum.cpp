class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res;
        unordered_map <int, int> myMap;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::const_iterator got = myMap.find(target - nums[i]);
            if (got == myMap.end())
                myMap[nums[i]] = i;
            else {
                res.push_back (i);
                res.push_back (myMap[target - nums[i]]);
                break;
            }
        }
        return res;
    }
};
