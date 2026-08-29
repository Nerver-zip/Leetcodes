class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestInc = 1;
        int longestDec = 1;

        int count = 1;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] < nums[i+1]){
                count++;
                if(count > longestInc)
                    longestInc = count;
            }
            else
                count = 1;
        }

        count = 1;
        for (int j = 0; j < nums.size()-1; j++)
        {
            if (nums[j] > nums[j+1]){
                count++;
                if(count > longestInc)
                    longestInc = count;
            }
            else
                count = 1;
        }
        return std::max(longestInc,longestDec);
    }
};