class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> freq_freq; 

        for(int n : nums)
            ++freq[n];

        for(const auto& [n, freq] : freq)
            ++freq_freq[freq];

        for(int n : nums){
            int f = freq[n];
            
            if(freq_freq[f] == 1)
                return n;
        }

        return -1;
    }
};