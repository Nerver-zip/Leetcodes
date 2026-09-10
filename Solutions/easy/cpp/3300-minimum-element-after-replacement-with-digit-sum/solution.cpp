class Solution {
public:
    int minElement(vector<int>& nums) {
        auto sumDigits = [](int n){
            string s = to_string(n);
            
            int sum = 0;
            for(char c : s){
                sum += c - '0';
            }
            
            return sum;
        };
        
        int ans = numeric_limits<int>::max();
        for(int n : nums)
            ans = min(ans, sumDigits(n));

        return ans;
    }
};