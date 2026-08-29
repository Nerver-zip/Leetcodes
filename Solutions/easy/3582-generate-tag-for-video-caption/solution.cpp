#define CHARCONST 32
class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        bool seenSpace = false;
        for (int i = 0; i < caption.size() && ans.size() < 100; ++i)
        {
            if (caption[i] == ' ' && ans.back() != '#')
                seenSpace = true;
            else if(seenSpace && caption[i] != ' ')
            {
                if(caption[i] > 'Z')
                    ans += caption[i] - CHARCONST; //to upper
                else
                    ans += caption[i];
                seenSpace = false;
            }
            else if (!seenSpace && caption[i] != ' ')
            {
                if(caption[i] < 'a')
                    ans += caption[i] + CHARCONST; //to lower
                else
                    ans += caption[i];
                seenSpace = false;
            }
        }
        return ans;
    }
};
