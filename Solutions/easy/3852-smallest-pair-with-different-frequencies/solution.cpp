class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> ans(2,-1);

        map<int,int> freq;

        for(int n : nums)
            freq[n]++;
        
        
        int lastFreq = freq.cbegin()->second;
        ans[0] = freq.cbegin()->first; 
        
        for(const auto& [n, f] : freq){
            if(f != lastFreq){
                ans[1] = n;
                return ans;
            }
        }

        return ans[1] == -1 ? vector<int>(2,-1) : ans;
    }
};