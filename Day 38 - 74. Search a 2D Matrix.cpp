class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        for (int i = 0; i < rows; i++) {
            if (target < matrix[i][0]) {
                return false;
            }
            if (target > matrix[i][matrix[i].size() - 1]) {
                continue;
            }
            int start = 0, end = matrix[i].size() - 1;
            int mid;
            while (start <= end) {
                mid = (start + end) / 2;
                if (target == matrix[i][mid]) {
                    return true;
                } else if (target > matrix[i][mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            return false;
        }
        return false;
    }
};
