class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        auto getDigits = [](int x){
            vector<int> res;

            while(x){
                res.push_back(x % 10);
                x /= 10;
            }

            reverse(res.begin(), res.end());
            return res;
        };
        
        vector<int> ans;

        for(int n : nums){
            auto digits = getDigits(n);
            for(int d : digits)
                ans.push_back(d);
        }

        return ans;
    }
};