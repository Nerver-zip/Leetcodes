class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); ++i)
            map[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            
            auto it = map.find(diff);
            
            if(it != map.end() && it->second != i){
                return {i, it->second};
            }
        }

        return {};
    }
};