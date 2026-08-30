class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> map;
    
        map[nums[0]] = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i-1] != nums[i]){
                ++map[nums[i]];
            }
        }
        
        for(const auto& [n, freq] : map){
            if(freq == 1)
                ++ans;
        }

        return ans;
    }
};