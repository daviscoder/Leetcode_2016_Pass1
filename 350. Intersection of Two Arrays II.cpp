class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
            myMap[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++) {
            if (myMap.count (nums2[i]) && myMap[nums2[i]] > 0) {
                res.push_back (nums2[i]);
                myMap[nums2[i]]--;
            }
        }
        return res;
    }
};
