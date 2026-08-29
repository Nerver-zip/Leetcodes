class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int n = s.size();
        string ans = string(101, '1');
        
        int oneCount = 0;
        int smallestSize = n; 
        for(int left = 0, right = 0; right < n; ++right){
            if(s[right] == '1')
                ++oneCount;

            while(oneCount > k){
                if(s[left] == '1'){
                    --oneCount;
                }
                ++left;
            }

            // pad left zeros
            while(left < right && s[left] == '0'){
                ++left;
            }

            if(oneCount == k && right - left + 1 < smallestSize){
                smallestSize = right - left + 1;
                ans = std::string(s.begin() + left, s.begin() + right + 1);
            }

            if(oneCount == k && right - left + 1 <= smallestSize){
                ans = min(ans, std::string(s.begin() + left, s.begin() + right + 1));
            }
        }

        return ans.size() == 101 ? "" : ans;
    }
};