class Solution {
public:
    string smallestSubsequence(string s) {
        array<int, 26> freq{};
        array<bool, 26> inStack{};

        string ans;

        for(char c : s){
            ++freq[c - 'a'];
        }

        for(char c : s){
            --freq[c - 'a'];

            if(inStack[c - 'a']){
                continue;
            }

            while(!ans.empty() && ans.back() >= c && freq[ans.back() - 'a'] > 0){
                inStack[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += c;
            inStack[c - 'a'] = true;
        }

        return ans;
    }
};