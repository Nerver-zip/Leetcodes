class Solution {
public:
    bool divideArray(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());

        for (int i = 0, j = 1; j < nums.size(); i+=2, j+=2)
        {
            if (nums[i] != nums[j])
                return false;
        }
        return true;        
    }
};