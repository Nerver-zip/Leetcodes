class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string> ans;
        std::unordered_map<char,int> maxFreq;
        for (const auto& word : words2)
        {
            std::unordered_map<char,int> currFreq;
            for (char c : word)
            {
                currFreq[c]++;
                maxFreq[c] = std::max(maxFreq[c],currFreq[c]);
            }
        }
        
        for(const auto& word : words1){
        
                std::unordered_map<char,int> charFreq1;
                bool isSubset = true;
                for (char c : word)
                {
                    charFreq1[c]++;
                }
                
                for (auto const& element : maxFreq)
                {
                    if (charFreq1[element.first] < maxFreq[element.first])
                    {
                        isSubset = false;
                        break;
                    }
                }   
                if (isSubset)
                    ans.push_back(word);
            }
        return ans;
    }
};