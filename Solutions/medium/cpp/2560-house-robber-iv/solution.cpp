class Solution {
private:
    bool hasKLowerElements(const vector<int>& nums, int k, int pivot){
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= pivot)
            {
                count++;
                i++;
                if(count == k) 
                    return true;
            }
        }
        return false;
    }

    void binarySearchInterval(const vector<int>& nums, int k, int left, int right, int& ans){
        if (left <= right)
        {
            int mid = left + (right-left)/2;

            if (hasKLowerElements(nums, k, mid))
            {
                ans = mid;
                return binarySearchInterval(nums,k,left,mid-1,ans);
            }
            return binarySearchInterval(nums,k,mid+1,right,ans);
        }
        return;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        
        int leftBound = nums[0], rightBound = nums[0];
        for (const auto& n : nums)
        {
            if (n < leftBound)
                leftBound = n;
            else if(n > rightBound)
                rightBound = n;
        }
        int ans;
        binarySearchInterval(nums,k,leftBound,rightBound,ans);
        return ans;
    }
};
