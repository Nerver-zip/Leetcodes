class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> ans;

        for(int n : nums)
            if(!set.insert(n).second)
                ans.push_back(n);
        return ans;
    }
};