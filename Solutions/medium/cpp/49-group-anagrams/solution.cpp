class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;

        for (const auto& str : strs)
        {
            vector<int> frequency(26, 0);
            for (const auto& c : str)
                frequency[c - 'a']++;
            
            string key;

            for (const auto& n : frequency)
            {
                key += std::to_string(n) + ';'; //separator to avoid colisions
            }
            groups[key].push_back(str);
        }

        vector<vector<string>> ans;
        int i = 0;

        for (const auto& group : groups)
        {   
            ans.push_back(group.second);
        }
        return ans;
    }
};