class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        vector<char> letters; 

        for(char c : word){
            if(freq[c - 'a'] == 0)
                letters.push_back(c);

            ++freq[c - 'a'];
        }
    
        ranges::sort(letters, [&](char a, char b){
            return freq[a - 'a'] > freq[b - 'a']; 
        });
        
        vector<int> minPushes(26, 4);
        
        int count = 0;
        for(char c : letters){
            int pushes = count / 8 + 1;
            minPushes[c - 'a'] = pushes;
            ++count;
        }
        
        int ans = 0;
        for(char c : word)
            ans += minPushes[c - 'a'];

        return ans;
    }
};