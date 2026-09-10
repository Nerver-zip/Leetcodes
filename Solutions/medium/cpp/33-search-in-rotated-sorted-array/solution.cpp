class Solution {
private:
    int binarySearch(const vector<int>& nums, int left, int right, int target){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                return binarySearch(nums, left, mid-1, target);
            return binarySearch(nums, mid+1, right, target);
        }
        return -1;
    }

    int findPivot(const vector<int>& nums, int left, int right){
        if (left < right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right])
                return findPivot(nums, mid+1, right);
            return findPivot(nums, left, mid);
        }
        return left;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size()-1);
        if (pivot == 0)
        {
            return binarySearch(nums, 0, nums.size()-1, target);
        }
        if (target == nums[pivot])
        {
            return pivot;
        }
        if (target > nums[pivot-1])
        {
            return -1;
        }
        if (target < nums[pivot])
        {
            return -1;
        }
        if (target > nums[pivot] && target <= nums[nums.size()-1])
        {
            return binarySearch(nums, pivot+1, nums.size()-1, target);
        }
        return binarySearch(nums, 0, pivot, target);
    }
};