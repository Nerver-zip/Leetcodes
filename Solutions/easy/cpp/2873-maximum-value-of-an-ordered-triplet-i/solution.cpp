class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxTriplet = LLONG_MIN;
        for (int i = 0; i < nums.size()-2; i++)
        {
            for (int j = i+1; j < nums.size()-1; j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    maxTriplet = std::max(maxTriplet, (static_cast<long long>((nums[i] - nums[j])) * nums[k]));
                }
            }
        }
        return maxTriplet <= 0 ? 0 : maxTriplet;
    }
};