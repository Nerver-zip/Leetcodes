class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        const int size = 101;
        vector<int> freq(size, 0);
        
        int maxFreq = INT32_MIN;

        for (int n : nums) {
            ++freq[n];
            if(freq[n] > maxFreq)
                maxFreq = freq[n];
        }
        
        int ans = 0;

        for(int i = 0; i < size; ++i){
            if(freq[i] == maxFreq){
                ans += freq[i];
            }
        }

        return ans;
    }
};