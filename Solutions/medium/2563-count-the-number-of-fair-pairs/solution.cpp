class Solution {
private:
    int binarySearchUpperBound(const vector<int>& nums, int left, int right, int curr, int bound, int& ans){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            if (curr + nums[mid] <= bound)
            {
                ans = mid;
                return binarySearchUpperBound(nums, mid+1, right, curr, bound, ans);
            }
            return binarySearchUpperBound(nums, left, mid-1, curr, bound, ans);
        }
        return ans;
    }

    int binarySearchLowerBound(const vector<int>& nums, int left, int right, int curr, int bound, int& ans){
        if (left <= right)
        {
            int mid = left + (right-left)/2;
            if (curr + nums[mid] >= bound)
            {
                ans = mid;
                return binarySearchLowerBound(nums, left, mid-1, curr, bound, ans);
            }
            return binarySearchLowerBound(nums, mid+1, right, curr, bound, ans);
        }
        return ans;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 1)
            return 0;
        
        std::sort(nums.begin(), nums.end());

        int init_left = -1;
        int init_right = -1;

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int left = binarySearchLowerBound(nums, i+1, nums.size()-1, nums[i], lower, init_left);
            int right = binarySearchUpperBound(nums, i+1, nums.size()-1, nums[i], upper, init_right);
            if(left != -1 && right != -1)
                ans += right-left+1;
            init_right = -1;
            init_left = -1;
        }
        return ans;
    }
};