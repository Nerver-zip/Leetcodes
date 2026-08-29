class Solution {
private:
    int binarySearchInterval(const vector<vector<int>>& matrix, int left, int right, int target){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            int size = matrix[0].size();
            if (matrix[mid][0] <= target && matrix[mid][size-1] >= target)
            {
                return mid;
            }
            if(matrix[mid][0] > target && matrix[mid][size-1] > target)
                return binarySearchInterval(matrix, left, mid-1, target);
            return binarySearchInterval(matrix, mid+1, right, target);
        }
        return -1;
    }
    bool binarySearch(const vector<int>& nums, int left, int right, int target){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
                return true;
            if(nums[mid] > target)
                return binarySearch(nums, left, mid-1, target);
            return binarySearch(nums, mid+1, right, target);
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index = binarySearchInterval(matrix, 0, matrix.size()-1, target);
        if(index == -1)
            return false;
        return binarySearch(matrix[index], 0, matrix[index].size()-1, target);
    }
};