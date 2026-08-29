class Solution {
private:
    bool isPeak(const vector<int>& nums, int index){
        if(index == 0)
        {
            return nums[index] > nums[index+1];
        }
        if (index == nums.size()-1)
        {
            return nums[index] > nums[index-1];
        }
        return nums[index] > nums[index-1] && nums[index] > nums[index+1]; 
    }
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int half1 = left + (right-left)/2;
            int half2 = half1+1;

            if (isPeak(nums, half1))
            {
                return half1;
            }
            
            if (isPeak(nums, half2))
            {
                return half2;
            }

            if (nums[half1] > nums[half2])
                right = half1 - 1;
            else
                left = half2 + 1;

        }
        return -1;
    }
};