class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int ROWS = strs.size();
        const int COLS = strs[0].size();
        int ans = 0;
        for (int i = 0; i < COLS; ++i) {
            string curr;
            for (int j = 0; j < ROWS; ++j) {
                curr += strs[j][i];
            }
            string cmp = curr;
            sort(curr.begin(), curr.end());
            cout << cmp << "\n";
            cout << curr << "\n";
            if(cmp != curr)
                ++ans;
        } 
        
        return ans;
    }
};