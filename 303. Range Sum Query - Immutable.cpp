class NumArray {
public:
    map<int, int> mp;
    NumArray(vector<int> &nums) {
        int sum = 0;
        mp[-1] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mp[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        return mp[j] - mp[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
