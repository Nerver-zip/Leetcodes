class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10)
            return {};
        unordered_map<string, int> sequenceFreq;

        int left = 0;
        for (int right = 0; right < s.size(); ++right)
        {
            int size = right - left + 1;
            if (size > 10){
                left++;
                size--;
            }
            if(size == 10){
                sequenceFreq[s.substr(left, 10)]++;
            }
        }
        
        vector<string> ans;
        for (const auto& [substring, freq] : sequenceFreq)
            if(freq > 1)
                ans.push_back(substring);
        return ans; 
    }
};