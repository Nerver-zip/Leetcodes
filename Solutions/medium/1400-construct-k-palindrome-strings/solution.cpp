class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k)
            return false;

        std::unordered_map<char,int> freq;
        int oddCount = 0;
        int evenCount = 0;

        for(const auto& c : s){
            freq[c]++;
        }

        for(const auto& [letter, frequency] : freq){
            if (frequency % 2 != 0)
                oddCount++;
        }
    
        return oddCount <= k;
    }
};