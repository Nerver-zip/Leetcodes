class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int *indexMap = nullptr;
        indexMap = new int[nums.size()];
        int violations = 0;
        vector<bool> ans;
        indexMap[0] = 0;
        
        for (int i = 0; i < nums.size()-1; i++)
        {
            if((nums[i] % 2 == nums[i+1] % 2))
               indexMap[i+1] = ++violations;
            else
               indexMap[i+1] = violations;    
        }
        
        for (auto query : queries){
            if (indexMap[query[0]] - indexMap[query[1]] == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        delete[] indexMap;
        return ans;
    }
};