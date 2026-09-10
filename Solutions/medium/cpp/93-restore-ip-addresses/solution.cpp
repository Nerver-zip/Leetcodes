class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12)
            return vector<string>();

        string res;
        backtrack(s, 0, res, 0);
        return ans;
    }
private:
    vector<string> ans;

    void backtrack(const string& s, int i, string res, int dots){
        if(res.size() == s.size() + 3 && isValid(split(res)))
            ans.push_back(res);
        
        if(i == s.size())
            return;

        // Prune dead state
        int remaining_dots = 4 - dots, remaining_s = s.size()-i;
        if(remaining_s / remaining_dots > 3)
            return;
        
        res.push_back(s[i]);
        
        // only place dot if it's possible to form ip with remaining dots
        // in order words: (remaining s / remaining dots) <= 3
        if(dots < 3){
            res.push_back('.');
            backtrack(s, i+1, res, dots+1);
            res.pop_back();
        }

        backtrack(s, i+1, res, dots);
    }
    
    vector<string> split(const string& s) {
        vector<string> tokens;

        for (auto&& part : s | views::split('.')) {
            tokens.emplace_back(part.begin(), part.end());
        }

        return tokens;
    }

    bool isValid(const vector<string>& s){
        for(const auto& split : s){
            if(split.size() > 3 || split.empty())
                return false;
            if(split.size() > 1 && split.front() == '0')
                return false;

            const int n = stoi(split);

            if(n > 255)
                return false;
        }
        return true;
    }
};