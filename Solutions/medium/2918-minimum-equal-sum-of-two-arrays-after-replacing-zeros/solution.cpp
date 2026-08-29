class Solution {
private:
    pair<long, long> sum_Zero(const vector<int>& nums){
        pair<long, long> res(0,0);
        for (int i = 0; i < nums.size(); ++i)
        {
            res.first += nums[i];
            res.second = nums[i] == 0 ? res.second+1 : res.second;
        }
        return res;
    } 
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        const int limit = INT32_MAX;
        auto sum1 = sum_Zero(nums1);
        auto sum2 = sum_Zero(nums2);

        long long minSum1 = sum1.first + sum1.second;
        long long minSum2 = sum2.first + sum2.second;

        if (minSum1 > minSum2)
        {
            long long diff = minSum1 - minSum2;
            long long max = sum2.second * limit;
            if (max == 0 || diff % max != diff)
            {
                return -1;
            }
            return minSum1;
        }
        if (minSum1 < minSum2)
        {
            long long diff = minSum2 - minSum1;
            long long max = sum1.second * limit;
            if (max == 0 || diff % max != diff)
            {
                return -1;
            }
            return minSum2;
        }
        return minSum1;
    }
};