class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> numsFreq;

        for (int n : nums)
            numsFreq[n]++;
        
        int ans = 0;
        for (const auto& [n, freq] : numsFreq)
        {
            if(numsFreq.find(n+1) != numsFreq.end())
                ans = max(ans, numsFreq[n] + numsFreq[n+1]);
            if(numsFreq.find(n-1) != numsFreq.end())
                ans = max(ans, numsFreq[n] + numsFreq[n-1]);
        }
        return ans;
    }
};