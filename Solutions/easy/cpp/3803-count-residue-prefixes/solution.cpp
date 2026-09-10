class Solution {
public:
    int residuePrefixes(string s) {
        int ans = 0;
        unordered_set<char> set;

        for (int i = 0; i < s.size(); ++i) {
            set.insert(s[i]);
            if(set.size() == (i + 1) % 3)
                ++ans;
        }

        return ans;
    }
};