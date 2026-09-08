class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string sanitized;

        for(char c : s)
            if(c != '-')
                sanitized += toupper(c);

        string ans;
        if(!sanitized.empty()){
            int firstGroup = (int)sanitized.size() % k;

            
            for (int i = 0; i < firstGroup; ++i) {
                ans += sanitized[i];
            }

            if(!ans.empty())
                ans += '-';
            
            int count = 0;
            for (int i = firstGroup; i < sanitized.size(); ++i) {
                ans += sanitized[i];
                count++;
                
                if(count == k){
                    ans += '-';
                    count = 0;
                }
            }

            if(ans.back() == '-')
                ans.pop_back();
        }
        
        return ans;
    }
};
