class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOcurrance(26,-1);
        vector<int> ans;

        for (int i = 0; i < s.size(); i++)
            lastOcurrance[s[i] - 'a'] = i;
        
        int last = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int minRight = lastOcurrance[s[i] - 'a'];
            while (minRight > i)
            {
                i++;
                if(lastOcurrance[s[i] - 'a'] > minRight)
                    minRight = lastOcurrance[s[i] - 'a'];
            }
            ans.push_back(i - last);
            last = i;
        }
        return ans;
    }
};