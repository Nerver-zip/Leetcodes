class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n + 1, 0);

        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];

            diffArray[left] -= 1;
            diffArray[right + 1] += 1;
        }
        
        //Apply changes
        int currentDecrement = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentDecrement += diffArray[i];  
            nums[i] += currentDecrement;
            if (nums[i] > 0) return false;  
        }       
        return true;
    }
};