class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            count += (s[i] == '1') ? 1 : -1;
            
            if (count == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                blocks.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        sort(blocks.rbegin(), blocks.rend());

        string result;
        for (auto &b : blocks) 
            result += b;
        return result;
    }
};