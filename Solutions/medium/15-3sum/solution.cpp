class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(),nums.end());
        std::unordered_map<int,int> myMap;

        for (int i = 0; i < nums.size(); i++)
            myMap[nums[i]] = i;
        
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size()-2 && nums[i] <= 0; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size()-1; j++)
            {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int tgt = -(nums[i] + nums[j]);
                if (myMap.find(tgt) != myMap.end() && i < myMap[tgt] && j < myMap[tgt])
                {
                    ans.push_back({nums[i],nums[j],tgt});
                }
            }
        }
        return ans;
    }
};