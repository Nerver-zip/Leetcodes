class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maximum = *max_element(nums.begin(), nums.end());
        long long minimum = *min_element(nums.begin(), nums.end());
        
        return (maximum - minimum) * k;
    }
};