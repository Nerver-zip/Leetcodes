class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;

        for(const auto& chunk : chunks)
            s += chunk;
        
        unordered_map<string, int> words;
        string word = "";

        while(!s.empty() && !(s.back() >= 'a' && s.back() <= 'z'))
            s.pop_back();
        
        for(char c : s){
            if(c >= 'a' && c <= 'z')
                word += c;
            else if(!word.empty() && c == '-' && word.back() != '-')
                word += c;
            else if(word.size() > 0){
                if(word.back() == '-')
                    word.pop_back();
                ++words[word];
                word.clear();
            }
        }
        
        ++words[word];
        
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++i)
            ans[i] = words[queries[i]];
        
        return ans;
    }
};