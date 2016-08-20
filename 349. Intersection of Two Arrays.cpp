class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res;
        if (nums1.size() <= 0 || nums2.size() <= 0)
            return res;
        unordered_set <int> my_set;
        for (int i = 0; i < nums1.size(); i++) {
            unordered_set<int>::const_iterator got = my_set.find (nums1[i]);
            if (got == my_set.end())
                my_set.insert (nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            unordered_set<int>::const_iterator got = my_set.find (nums2[i]);
            if (got != my_set.end()) {
                res.push_back (nums2[i]);
                my_set.erase (got);
            }
        }
        return res;
    }
};
