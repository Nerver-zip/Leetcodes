class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        auto isIncreasing = [&](int idx, int size){
            for(int i = idx + 1; i <= size; ++i){
                if(nums[i-1] >= nums[i])
                    return false;
            }
            return true;
        };

        auto isDecreasing = [&](int idx, int size){
            for(int i = idx + 1; i <= size; ++i){
                if(nums[i-1] <= nums[i])
                    return false;
            }
            return true;
        };
        
        const int n = nums.size();
        for (int p = 1; p <= n - 3; p++) {
            if (!isIncreasing(0, p)) continue;
            for (int q = p + 1; q <= n - 2; q++) {
                if (!isDecreasing(p, q)) continue;
                if (isIncreasing(q, n - 1))
                    return true;
            }
        }
        return false;
    }
};