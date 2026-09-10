class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

       int i = 0;
       int j = 0;
       while (str1[i] != '\0' && str2[j] != '\0')
       {
        if (str1[i] == str2[j])
        {
            j++;
        }
        else if (str1[i] + 1 == str2[j] || str1[i] == 'z' && str2[j] == 'a'){
            j++;
        }
        i++;
       }
        return j == str2.size();
    }
};