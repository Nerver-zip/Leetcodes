class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, unordered_set<int>> friendLangs; //maps a friend to a set of known languages
        
        for (int i = 0; i < languages.size(); ++i)
            for (int lang : languages[i]) 
                friendLangs[i+1].insert(lang);

        unordered_set<int> candidates;

        for (const auto& friendship : friendships) {
            int u = friendship[0], v = friendship[1];
            const auto& u_langs = friendLangs[u];
            bool common = false;
            for (const auto& lang : u_langs) {
                if(friendLangs[v].count(lang)){
                    common = true;
                    break;
                }
            }
            if(!common){
                candidates.insert(u);
                candidates.insert(v);
            }    
        }

        int ans = INT32_MAX;
        
        for (int lang = 1; lang <= n; ++lang) {
            int knows = 0;
            for (const int& f : candidates) {
                if(friendLangs[f].count(lang))
                    ++knows;
            }
            ans = min(ans, (int)candidates.size() - knows);
        }

        return ans == INT32_MAX ? 0 : ans;
    }
};