class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.size();
        array<int, 3> freq{};

        auto check = [&](){
            return freq[0] && freq[1] && freq[2];
        };

        int ans = 0;

        for(int left = 0, right = 0; right < s.size(); ++right){
            ++freq[s[right] - 'a'];

            while(check()){
                ans += n - right;
                --freq[s[left] - 'a'];
                ++left;
            }
        }
        
        return ans;
    }
};