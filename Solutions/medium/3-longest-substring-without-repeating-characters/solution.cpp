class Solution {
private:
    bool hasDuplicates(const vector<int>& symbolFreq){
        for (const auto& freq : symbolFreq)
        {
            if(freq > 1)
                return true;
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> symbolFreq(124, 0);
        int right = 0, left = 0, ans = 0;
        
        for (right; right < s.size(); ++right)
        {
            symbolFreq[s[right] - ' ']++;
            while (hasDuplicates(symbolFreq))
            {  
                symbolFreq[s[left] - ' ']--;
                left++;
            }
            ans = max(right - left + 1, ans);
        }
        return ans;
    }
};
