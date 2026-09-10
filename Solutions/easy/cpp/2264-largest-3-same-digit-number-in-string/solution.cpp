class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for (int i = 0; i < num.size()-2; ++i) {
            string curr = num.substr(i, 3);
            if(curr[0] != curr[1] || curr[1] != curr[2])
                continue;
            if(strcmp(curr.c_str(), ans.c_str()) > 0)
                ans = curr;
        }
        return ans;
    }
};