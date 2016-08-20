/* 2 solutions:
  1. Binary search. Count the middle number.
  2. Find linked list entry. http://bookshadow.com/weblog/2015/09/28/leetcode-find-duplicate-number/

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        int finder = 0;
        while (1) {
            finder = nums[finder];
            slow = nums[slow];
            if (slow == finder)
                return slow;
        }
        return 0;
    }
};
