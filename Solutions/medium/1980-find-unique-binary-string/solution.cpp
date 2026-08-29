class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> set(nums.begin(), nums.end());

        for(auto& s : nums){
            s[0] = s[0] == '1' ? '0' : '1';
            
            if(!set.count(s))
                return s;
        }

        return string(nums[0].size(), '1');
    }
};