class Solution {
public:
    int longestBalanced(string s) {
            
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            array<int, 26> freq = {};
            
            auto isBalanced = [&freq = std::as_const(freq)](){
                int last = 0;
                for(int f : freq){
                    if(f == 0)
                        continue;
                    if(last != f && last != 0)
                        return false;
                    last = f;
                }
                return true;
            };

            for(int j = i; j < s.size(); ++j){
                ++freq[s[j] - 'a'];
                if(isBalanced())
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};