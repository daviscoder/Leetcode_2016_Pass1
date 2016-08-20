class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int start = 0, end = citations.size(), length = citations.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid < citations[length - mid - 1])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};
