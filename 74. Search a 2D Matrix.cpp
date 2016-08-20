class Solution {
public:
    int search_row (vector<vector<int>>& matrix, int begin, int end, int target) {
        if (begin == end)
            return begin;
        int mid = begin + (end - begin) / 2;
        if (matrix[mid][matrix[0].size() - 1] >= target)
            return search_row (matrix, begin, mid, target);
        else
            return search_row (matrix, mid + 1, end, target);
    }
    
    bool search_element (vector<int>array, int begin, int end, int target) {
        if (begin == end)
            return array[begin] == target? true : false;
        int mid = begin + (end - begin) / 2;
        if (array[mid] >= target)
            return search_element (array, begin, mid, target);
        else
            return search_element (array, mid + 1, end, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = search_row (matrix, 0, matrix.size() - 1, target);
        return search_element (matrix[row], 0, matrix[0].size() - 1, target);
    }
};
