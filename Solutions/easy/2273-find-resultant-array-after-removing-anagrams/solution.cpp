class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        const int N = words.size();
        vector<string> ans;
        array<int, 26> lastFreq{};
         
        ans.push_back(words[0]);
        
        for(char c : words[0])
            ++lastFreq[c - 'a'];
        
        array<int, 26> currFreq;
        for (int i = 1; i < N; ++i) {
            currFreq.fill(0);

            for(char c : words[i])
                ++currFreq[c - 'a'];
            
            bool isAnagram = true;
            for (int j = 0; j < 26; ++j){
                if(ans.back().size() != words[i].size() || lastFreq[j] != currFreq[j]){
                    isAnagram = false;
                    break;
                }
            }

            if(!isAnagram){
                ans.push_back(words[i]);
                lastFreq = currFreq;
            }
        }
        return ans;
    }
};