class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        else if (m == 0) {
            for (int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        int p = m + n - 1, i = m - 1, j = n - 1;
        for (; i >= 0 && j >= 0;p--) {
            if (nums1[i] > nums2[j]) {
                nums1[p] = nums1[i];
                i--;
            }
            else {
                nums1[p] = nums2[j];
                j--;
            }
        }
        if (i == -1)
            for (int i = 0; i <= p; i++)
                nums1[i] = nums2[i];
    }
};
