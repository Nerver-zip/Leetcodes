class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> nums(n, 0);
        int left = 0, right = n - 1;
        
        int diff = 1;
        while (left < right) {
            nums[left] -= diff;
            nums[right] += diff;
            ++diff; ++left; --right;
        }
        return nums;
    }
};