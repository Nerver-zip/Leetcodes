class Solution {
public:
    string sortVowels(string s) {
        const int n = s.size();

        vector<int> vowels;
        vowels.reserve(s.size());
        
        unordered_map<char, int> freq;
        unordered_map<char, int> firstOccur;

        firstOccur['a'] = numeric_limits<int>::max();
        firstOccur['e'] = numeric_limits<int>::max();
        firstOccur['i'] = numeric_limits<int>::max();
        firstOccur['o'] = numeric_limits<int>::max();
        firstOccur['u'] = numeric_limits<int>::max();

        for(int i = 0; i < n; ++i)
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowels.push_back(s[i]);
                ++freq[s[i]];
                if(firstOccur[s[i]] == numeric_limits<int>::max())
                    firstOccur[s[i]] = i;
            }

        sort(vowels.begin(), vowels.end(), [&](const auto& a, const auto& b){
            return freq[a] == freq[b] ? firstOccur[a] < firstOccur[b] : freq[a] > freq[b]; 
        });

        string ans;
        int i = 0;
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                ans += vowels[i];
                ++i;
            }
            else
                ans += c;
        }

        return ans;
    }
};