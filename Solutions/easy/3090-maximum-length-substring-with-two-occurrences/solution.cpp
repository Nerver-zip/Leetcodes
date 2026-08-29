class Solution {
public:
    int maximumLengthSubstring(string s) {
        array<int,26> freq{};
        
        auto validate = [&](){
            for(int f : freq){
                if(f > 2)
                    return false;
            }

            return true;
        };

        int ans = 0;
        for(int left = 0, right = 0; right < s.size(); ++right){
            ++freq[s[right] - 'a'];

            while(!validate()){
                --freq[s[left] - 'a'];
                ++left;
            }

            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};