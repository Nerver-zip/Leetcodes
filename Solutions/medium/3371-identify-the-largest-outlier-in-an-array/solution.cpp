#define INF_MIN -1000000000
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = 0;
        std::unordered_map<int,int> elementMap;

        for (const auto& n : nums){
            elementMap[n]++;
            totalSum += n;
        }
              
        int curr = 0;
        int ans = INF_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            curr = totalSum - nums[i];
            if (curr % 2 == 0)
            {
                int special = curr/2;
                if (elementMap.find(nums[i]) != elementMap.end()) 
                {
                    elementMap[nums[i]]--; 
                    if(elementMap[special] > 0)
                        ans = std::max(nums[i], ans);
                    elementMap[nums[i]]++;
                }
            }
        }
        return ans;  
    }
};