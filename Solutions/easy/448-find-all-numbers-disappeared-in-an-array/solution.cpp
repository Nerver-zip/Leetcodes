class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);

        for (int n : nums)
            ++freq[n];
        
        vector<int> ans;
        for (int n = 1; n < freq.size(); ++n) {
            if(freq[n] == 0)
                ans.push_back(n);
        }

        return ans;
    }
};
