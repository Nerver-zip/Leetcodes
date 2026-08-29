class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string cur) {
        if (cur.size() == 1) 
            return true;
        if (memo.count(cur)) 
            return memo[cur];

        int n = cur.size();
        vector<vector<char>> choices;

        for (int i = 0; i < n - 1; i++) {
            string key = cur.substr(i, 2);
            if (!mp.count(key)) 
                return memo[cur] = false;
            choices.push_back(mp[key]);
        }

        string next;
        function<bool(int)> gen = [&](int idx) {
            if (idx == choices.size()) {
                return dfs(next);
            }
            for (char c : choices[idx]) {
                next.push_back(c);
                if (gen(idx + 1)) 
                    return true;
                next.pop_back();
            }
            return false;
        };

        bool ok = gen(0);
        return memo[cur] = ok;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed)
            mp[s.substr(0,2)].push_back(s[2]);
        
        return dfs(bottom);
    }
};