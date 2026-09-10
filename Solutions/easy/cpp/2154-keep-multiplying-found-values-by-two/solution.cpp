class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        const int size = nums.size();
        int i = 0;

        while (i < size) {
            if(nums[i] == original){
                original *= 2;
                i = -1;
            }
            ++i;
        }

        return original;
    }
};
