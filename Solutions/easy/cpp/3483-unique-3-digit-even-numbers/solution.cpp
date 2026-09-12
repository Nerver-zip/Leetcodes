class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        const int n = digits.size();

        unordered_set<string> set;
        array<int, 10> freq{};

        for(int d : digits){
            ++freq[d];
        }

        auto backtrack = [&](auto&& self, string curr, int idx)->void{
            if(curr.size() == 3 && (curr.back() - '0') % 2 == 0){
                set.insert(curr);
                return;
            }
            for(int i = 0; i < n && curr.size() < 3; ++i){
                if(curr.empty() && digits[i] == 0){
                    continue;
                }
                if(freq[digits[i]]){
                    --freq[digits[i]];
                    curr.push_back(digits[i] + '0');
                    
                    self(self, curr, i+1);
                    
                    ++freq[curr.back() - '0'];
                    curr.pop_back();
                }
            }
        };
        
        backtrack(backtrack, "", 0);

        return set.size();
    }
};