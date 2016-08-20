class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0) {
            double small = findKthSmallest (nums1, nums2, total / 2, 0, 0);
            double large = findKthSmallest (nums1, nums2, total / 2 + 1, 0, 0);
            return (small + large) / 2;
        }
        else
            return findKthSmallest (nums1, nums2, total / 2 + 1, 0, 0);
    }

    double findKthSmallest (vector <int>& nums1, vector<int>& nums2, int index, int nums1Start, int nums2Start) {
        // Always make nums1's size is no larger than nums2's size.
        cout << index << "\t" << nums1Start << "\t" << nums2Start << endl;
        if (nums1.size() - nums1Start > nums2.size() - nums2Start)
            return findKthSmallest (nums2, nums1, index, nums2Start, nums1Start);
        if (nums1.size() - nums1Start == 0)
            return nums2[index - 1];
        if (index == 1)
            return min (nums1[nums1Start], nums2[nums2Start]);

        int nums1Index = min (index / 2, (int)nums1.size());
        int nums2Index = index - nums1Index;

        if (nums1[nums1Index + nums1Start - 1] < nums2[nums2Index + nums2Start - 1])
            return findKthSmallest (nums1, nums2, index - nums1Index, nums1Start + nums1Index, nums2Start);
        else if (nums1[nums1Index + nums1Start - 1] > nums2[nums2Index + nums2Start - 1])
            return findKthSmallest (nums1, nums2, index - nums2Index, nums1Start, nums2Start + nums2Index);
        else
            return nums1[nums1Index + nums1Start - 1];
    }
};
