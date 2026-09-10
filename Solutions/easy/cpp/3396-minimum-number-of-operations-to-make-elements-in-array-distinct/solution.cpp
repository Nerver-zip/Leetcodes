class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> positionMap(101);

        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (!positionMap[nums[i]])
            {
                positionMap[nums[i]] = true;
            }
            else
            {
                int ans = (i+1) / 3;
                return (i+1) % 3 != 0 ? ans + 1 : ans;
            }
        }
        return 0;
    }
};