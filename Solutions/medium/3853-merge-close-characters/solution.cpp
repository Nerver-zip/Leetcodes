class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans;
        
        for(char c : s){
            ans.push_back(c);
            for(int i = ans.size()-2; i >= 0; --i){
                if(ans[i] == ans.back() && ans.size() - i - 1 <= k){
                    ans.pop_back();
                    break;
                }
            }
        }
        
        return ans;
    }
};