class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {

        unordered_map<string, int> frequencyMap;
        int maxFreq = 0;

        for (const auto& response : responses)
        {
            unordered_set<string> seen;
            for (const auto& res : response)
            {
                if(seen.find(res) == seen.end()){
                    seen.insert(res);
                    frequencyMap[res]++;
                    if (frequencyMap[res] > maxFreq)
                        maxFreq = frequencyMap[res];
                }
            }
        }

        set<string> untie;
        for (const auto& [s, freq] : frequencyMap)
        {
            if (freq == maxFreq)
                untie.insert(s);
        }
        return *untie.begin();
    }
};