class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string> ans;
        string curr;

        for (char c : s)
        {
            curr += c;
            if (curr.size() == k)
            {
                ans.push_back(curr);
                curr = "";
            }
        }
        
        if (curr.size() != 0)
        {
            while (curr.size() < k)
            {
                curr += fill;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};