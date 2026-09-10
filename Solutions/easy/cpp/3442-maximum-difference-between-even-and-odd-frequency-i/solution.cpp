class Solution {
public:
    int maxDifference(string s) {
        vector<int> frequency(26, 0);

        for (char c : s)
            frequency[c - 'a']++;

        int maxOdd = 0;
        int minEven = INT32_MAX;
        for (int freq : frequency)
        {
            if(freq == 0)
                continue;
            if (freq % 2 == 0)
                minEven = min(minEven, freq);
            else
                maxOdd = max(maxOdd, freq);
        }        
        return maxOdd - minEven;
    }
};