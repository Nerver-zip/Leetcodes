class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        unordered_map<string, int> freq;
        for (const auto& word : words) { 
            string key;
            for(int i = 0; i < word.size() && i < k; ++i){
                key += word[i];
            }
            if(key.size() == k)
                ++freq[key];
        }
        int ans = 0;
        for(const auto& [_, f] : freq){
            if(f <= 1)
                continue;
            ++ans;
        } 
        return ans;
    }
};