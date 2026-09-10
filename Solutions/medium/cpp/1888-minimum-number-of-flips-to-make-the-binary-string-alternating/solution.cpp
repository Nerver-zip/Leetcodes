class Solution {
public:
    int minFlips(string s) {
        const int n = s.size();
        string s2 = s + s;

        int ans = INT32_MAX;
        int diff1 = 0, diff2 = 0;

        for(int left = 0, right = 0; right < s2.size(); ++right){
            char expected1 = (right % 2)  ? '1' : '0';
            char expected2 = (right % 2)  ? '0' : '1';
            
            if(expected1 != s2[right])
                ++diff1;
            if(expected2 != s2[right])
                ++diff2;

            if(right - left + 1 > n){
                char expected1_l = (left % 2)  ? '1' : '0';
                char expected2_l = (left % 2)  ? '0' : '1';
            
                if(expected1_l != s2[left])
                    --diff1;
                if(expected2_l != s2[left])
                    --diff2;
                ++left;
            }

            if(right - left + 1 == n)
                ans = min({ans, diff1, diff2});
        }

        return ans;
    }
};