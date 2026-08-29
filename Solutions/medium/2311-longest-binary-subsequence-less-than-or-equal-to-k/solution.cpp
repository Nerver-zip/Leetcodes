class Solution {
//Greedy: Initially, add as many 0's as possible, then start trying to add the right most 1's, calculating the gain of adding them
public:
    int longestSubsequence(string s, int k) {
        const int size = s.size();
        int ans = 0;

        for (char n : s)
            if (n == '0')
                ans++;

        long long totalGain = 0;
        int j = 0;
        for (int i = size - 1; i >= 0; --i)
        {
            if (s[i] == '1')
            {
                if (j > 33) //2e34 is already greater than max k 
                    return ans;
                totalGain += pow(2, j);
                if(totalGain > k)
                    return ans; 
                ans++;
            }
            ++j;
        }
        return ans;
    }
};