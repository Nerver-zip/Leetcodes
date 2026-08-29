class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int n : nums){
            if(freq[n] < k)
                ++freq[n];
        }

        vector<int> ans;

        for(int n : nums){
            if(freq[n]){
                ans.push_back(n);
                --freq[n];
            }
        }

        return ans;
    }
};