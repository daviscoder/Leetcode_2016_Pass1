// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int helper (int begin, int end) {
        if (begin == end)
            return isBadVersion (begin)? begin : begin + 1; // Watch out here!
        int mid = begin / 2 + end / 2 + 1;
        cout << mid << "." << endl;
        if (isBadVersion (mid) == false)
            return helper (mid, end);
        else
            return helper (begin, mid - 1);
    }
    int firstBadVersion(int n) {
        return helper (1, n);
    }
};
