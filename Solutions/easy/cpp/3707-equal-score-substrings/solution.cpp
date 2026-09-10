class Solution {
public:
    bool scoreBalance(string s) {
        bool flag = false;
        int firstSum = 0;
        for (int i = 0; i < s.size(); ++i) {
            firstSum += s[i] - 'a' + 1;
            int secondSum = 0;
            for (int j = i+1; j < s.size(); ++j)
                secondSum += s[j] - 'a' + 1;
            if(firstSum == secondSum)
                return true;
        }    
        return false;
    }
};