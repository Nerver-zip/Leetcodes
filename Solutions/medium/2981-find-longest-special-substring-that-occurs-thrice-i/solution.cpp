class Solution {
private:

    bool isSpecialSubString(string s, int left, int right){
        char letter = s[left]; 
        for (int i = left; i <= right; i++)
        {
            if (letter != s[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    int maximumLength(string s) {
        int left = 0;
        int right = s.size()-3;
        int currentLenght = right - left + 1;
    
        while(currentLenght > 0)
        {
            std::unordered_map<int,int> subStringMap;
            while (right < s.size())
            {
                if (isSpecialSubString(s,left,right)){
                    subStringMap[s[left]]++;
                    if (subStringMap[s[left]] >= 3)
                        return currentLenght;
                }
                right++;
                left++;
            }
            currentLenght--;
            left = 0;
            right = currentLenght-1;
        }
        return -1;
    }
};