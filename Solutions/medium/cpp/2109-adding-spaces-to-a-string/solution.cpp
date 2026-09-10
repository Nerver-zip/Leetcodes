class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newStr;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (j < spaces.size() && i == spaces[j])
            {
                newStr += ' ';
                j++;
            }
            newStr += s[i];
        }
        return newStr;
    }
};