class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int maxNum = nums[0];
        int minNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxNum = max (maxNum, nums[i]);
            minNum = min (minNum, nums[i]);
        }
        int len = (maxNum - minNum) / nums.size() + 1;
        vector<vector<int>> bucket ((maxNum - minNum) / len + 1);
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums[i] - minNum) / len;
            if (bucket[index].empty()) {
                bucket[index].push_back (nums[i]);
                bucket[index].push_back (nums[i]);
            }
            else {
                bucket[index][0] = min (bucket[index][0], nums[i]);
                bucket[index][1] = max (bucket[index][1], nums[i]);
            }
        }
        int gap = 0;  
        int prev = 0;
        cout << bucket.size();
        for (int i = 1; i < bucket.size(); i++) {  
            if (bucket[i].empty()) continue;
            gap = max(gap, bucket[i][0] - bucket[prev][1]);  
            prev = i;
        }
        return gap;
    }
};
