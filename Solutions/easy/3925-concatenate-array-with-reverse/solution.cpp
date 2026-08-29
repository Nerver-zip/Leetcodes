class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> temp = nums;

        reverse(temp.begin(), temp.end());

        nums.insert(nums.end(), temp.begin(), temp.end());

        return nums;
    }
};