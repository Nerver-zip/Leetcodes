class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int alternateParityLen = 1;
        int allEvenLen = 0;
        int allOddLen = 0;


        for(int n : nums){
            if(n % 2 == 0)
                ++allEvenLen;
            else
                ++allOddLen;
        }

        int curr = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            if((curr % 2 == 0 && nums[i] % 2 != 0) || (curr % 2 != 0 && nums[i] % 2 == 0)){
                ++alternateParityLen;
                curr = nums[i];
            }

        return max(alternateParityLen,max(allEvenLen, allOddLen));
    }
};