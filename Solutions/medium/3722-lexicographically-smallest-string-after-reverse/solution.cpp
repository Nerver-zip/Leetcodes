class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;

        for (int k = 0; k < s.size(); ++k) {
            string s1 = s.substr(0, k);
            string s2 = s.substr(k);
            
            string temp = s1;
            reverse(s1.begin(), s1.end());
            s1 += s2;

            reverse(s2.begin(), s2.end());
            s2 = temp + s2;

            ans = min({ans, s1, s2});
        }

        return ans;
    }
};