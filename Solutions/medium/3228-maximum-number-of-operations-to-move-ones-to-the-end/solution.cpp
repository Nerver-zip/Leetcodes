class Solution {
public:
    int maxOperations(string s) {  
        int oneCount = 0, ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '1')
                ++oneCount;
            else{
                while (i < s.size() && s[i] == '0')
                    ++i;
                ans += oneCount;
                --i; //adust after while() offset
            }
        }
        return ans;
    }
};