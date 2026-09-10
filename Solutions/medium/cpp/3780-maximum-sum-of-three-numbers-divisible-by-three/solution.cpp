class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> remainder_zero, remainder_one, remainder_two;

        for (int n : nums){
            if(n % 3 == 0)
                remainder_zero.push_back(n);
            else if(n % 3 == 1)
                remainder_one.push_back(n);
            else{
                remainder_two.push_back(n);
            }
        }
        
        sort(remainder_zero.begin(), remainder_zero.end(), [](const auto& a, const auto& b){return a > b;});
        sort(remainder_one.begin(), remainder_one.end(), [](const auto& a, const auto& b){return a > b;});
        sort(remainder_two.begin(), remainder_two.end(), [](const auto& a, const auto& b){return a > b;});
        
        //So, it's either first three zeros
        //or remainder one + remainder_one + remainder_one
        //or remainder_two + remainder_one + remainder_zero
        //or remainder_two * 3
        //GG >.<


        int maxSum = INT_MIN;
        
        if(remainder_zero.size() > 2)
            maxSum = remainder_zero[0] + remainder_zero[1] + remainder_zero[2];

        if(remainder_one.size() > 2)
            maxSum = max(maxSum, remainder_one[0] + remainder_one[1] + remainder_one[2]);

        if(remainder_two.size() > 2)
            maxSum = max(maxSum, remainder_two[0] + remainder_two[1] + remainder_two[2]);

        if(!remainder_zero.empty() && !remainder_one.empty() && !remainder_two.empty())
            maxSum = max(maxSum, remainder_zero[0] + remainder_one[0] + remainder_two[0]);

        return maxSum == INT_MIN ? 0 : maxSum;
    }
};