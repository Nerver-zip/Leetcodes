//Aka finding bottoms and tops in a stock price array
//A bottom is formed by a lower low between two lows, works the same for tops
//But, we need to first remove duplicate neighbors for this simple approach to work
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        
        vector<int> trimmed;
        int last = nums[0];
        trimmed.push_back(last);

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last)
                trimmed.push_back(nums[i]);
            last = nums[i];
        }    

        for (int i = 1; i < trimmed.size() - 1; ++i) {
            //bottoms
            if(trimmed[i] < trimmed[i-1] && trimmed[i] < trimmed[i+1])
                ++count;
            //top
            else if(trimmed[i] > trimmed[i-1] && trimmed[i] > trimmed[i+1])
                ++count;
        }
        return count;
    }
};