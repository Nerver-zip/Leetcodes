class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());

        int n = 1;
        while(true){
            if(!set.count(n) && n % k == 0){
                return n;
            }
            ++n;
        }

        return k;
    }
};