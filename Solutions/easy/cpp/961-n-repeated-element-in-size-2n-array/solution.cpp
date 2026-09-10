class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> freq;
        
        for (int n : nums) {
            ++freq[n];
            if(freq[n] == N/2)
                return n;
        }
        
        return -1;
    }
};