class Solution {
public:
    string reversePrefix(string s, int k) {
        auto ans = s.substr(0, k);

        reverse(ans.begin(), ans.end());

        ans += s.substr(k);

        return ans;
    }
};