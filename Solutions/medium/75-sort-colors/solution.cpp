class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        for(int& n : nums)
            switch (n)
            {
            case 0:
                zeroCount++;
                break;
            case 1:
                oneCount++;
                break;
            default:
                twoCount++;
                break;
            }
        
        int index = -1;
        while (zeroCount--)
            nums[++index] = 0;
        while (oneCount--)
            nums[++index] = 1;
        while (twoCount--)
            nums[++index] = 2;
    }
};