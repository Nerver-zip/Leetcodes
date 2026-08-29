class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount = 0;

        for (char c : s)
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ++vowelCount;

        return vowelCount == 0 ? false : true;
    }
};
