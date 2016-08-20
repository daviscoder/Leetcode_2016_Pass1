class TwoSum {
private:
    unordered_map<int, int> nums;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    nums[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
        for (auto a: nums) {
            int t = value - a.first;
            if ((t == a.first && nums[t] > 1) || (t != a.first && nums.count(t)))
                return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
