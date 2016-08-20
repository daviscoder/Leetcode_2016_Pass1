class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p = 0, q = 0;
        while (p < version1.size() || q < version2.size()) {
            int v1 = 0, v2 = 0;
            while (p < version1.size() && version1[p] != '.') {
                v1 = v1 * 10 + version1[p] - '0';
                p++;
            }
            while (q < version2.size() && version2[q] != '.') {
                v2 = v2 * 10 + version2[q] - '0';
                q++;
            }
            if (v1 > v2)
                return 1;
            else if (v1 < v2)
                return -1;
            p++;
            q++;
        }
        return 0;
    }
};
