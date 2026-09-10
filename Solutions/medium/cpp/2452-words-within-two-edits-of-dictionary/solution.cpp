class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(const auto& query : queries){
            for(const auto& word : dictionary){
                const int n = query.size();
                int diffs = 0;
                
                if(n != word.size())
                    continue;

                for(int i = 0; i < n; ++i){
                    if(query[i] != word[i])
                        ++diffs;
                    if(diffs > 2)
                        break;
                }
                
                if(diffs <= 2){
                    ans.push_back(query);
                    break;
                }
            }
        }

        return ans;
    }
};