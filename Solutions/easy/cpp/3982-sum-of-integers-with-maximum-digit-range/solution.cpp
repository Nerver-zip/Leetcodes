class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxDiff = 0;
        vector<int> diffs;
        diffs.reserve(nums.size());
        for(int n : nums){
            string s = to_string(n);

            char largest = '0', smallest = '9';

            for(char c : s){
                if(c > largest)
                    largest = c;
                if(c < smallest)
                    smallest = c;
            }

            int diff = largest - smallest;

            diffs.push_back(diff);
            maxDiff = max(maxDiff, diff);
        }
    
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(diffs[i] == maxDiff)
                ans += nums[i];
        }

        return ans;
    }
};