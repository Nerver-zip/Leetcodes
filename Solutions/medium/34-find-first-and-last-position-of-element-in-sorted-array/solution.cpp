class Solution {
private:
    int binarySearchLowerBound(const vector<int>& nums, int left, int right, int target, int& starting){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
            {
                starting = mid;
                return binarySearchLowerBound(nums, left, mid-1, target, starting);
            }
            if (nums[mid] > target)
                return binarySearchLowerBound(nums, left, mid-1, target, starting);
            return binarySearchLowerBound(nums, mid+1, right, target, starting);
        }   
        return starting;
    }

    int binarySearchUpperBound(const vector<int>& nums, int left, int right, int target, int& starting){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
            {
                starting = mid;
                return binarySearchUpperBound(nums, mid+1, right, target, starting);
            }
            if (nums[mid] > target)
                return binarySearchUpperBound(nums, left, mid-1, target, starting);
            return binarySearchUpperBound(nums, mid+1, right, target, starting);
        }   
        return starting;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1,-1};
        
        int starting = -1;
        vector<int> ans = {-1,-1};

        ans[0] = binarySearchLowerBound(nums, 0, nums.size()-1, target, starting);
        starting = -1;
        ans[1] = ans[0] != -1 ? binarySearchUpperBound(nums, ans[0], nums.size()-1, target, starting) : ans[1];

        return ans;
    }
};