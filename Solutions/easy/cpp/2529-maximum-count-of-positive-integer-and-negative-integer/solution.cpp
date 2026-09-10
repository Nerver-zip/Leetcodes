class Solution {
private:
        int leftBound(vector<int>& nums, int left, int right, int& bound){
        int mid = left + (right-left)/2;
        if (left <= right)
        {
            if (0 == nums[mid])
            {
                bound = mid;
                return leftBound(nums,left,mid-1, bound);
            }
            else if (0 < nums[mid])
                return leftBound(nums,left,mid-1, bound);
            else 
                return leftBound(nums,mid+1,right, bound);
        }
        return mid;
    }
    int rightBound(vector<int>& nums, int left, int right, int& bound){
        int mid = left + (right-left)/2;
        if (left <= right)
        {
            if (0 == nums[mid])
            {
                bound = mid;
                return rightBound(nums,mid+1,right, bound);
            }
            else if (0 < nums[mid])
                return rightBound(nums,left,mid-1, bound);
            else 
                return rightBound(nums,mid+1,right, bound);
        }
        return mid;
    }
public:
    int maximumCount(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0] != 0 ? 1 : 0;
        int l = -1;
        int r = -1;
        int c = leftBound(nums,0,size-1,l);
        int ans = 0;
        if (l == -1) //No zeros
        {
            //If c = 0, only positives, if c = size, only negatives, so return size
            if (c == 0 || c == size)
                return size;
            //otherwise return greatest size from the midpoint c
            return std::max(c, size - c);
        }
        //if theres a left bound, theres also a right bound
        rightBound(nums,l,size,r);
        
        //return greatest size from the midpoint c
        ans = std::max(l, size - r - 1);
        return ans;
    }
};