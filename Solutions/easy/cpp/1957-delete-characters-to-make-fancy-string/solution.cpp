class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        char curr = ' ';
        int count = 0;
        for (const auto& c : s) {
            if(curr == c)
                count++;
            else
                count = 0;
            if(count < 2)
                ans += c;
            curr = c;
        }
        return ans;
    }
};