class Solution {
private:
    unsigned nChoosek(unsigned n, unsigned k) {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;
        int result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
    return result;
}
public:

    long long countGood(vector<int>& nums, int k) {
        int left = 0;
        unordered_map<int,pair<int,int>> combinationMap;
        long long currCount = 0;
        long long ans = 0;
        
        for (int right = 0; right < nums.size(); right++)
        {
            currCount -= nChoosek(combinationMap[nums[right]].first, 2); //backtrack, removing contribution of current key before adding again
            combinationMap[nums[right]].first++;
            combinationMap[nums[right]].second = nChoosek(combinationMap[nums[right]].first, 2);
            currCount += combinationMap[nums[right]].second;
            while (currCount >= k)
            {
                ans += nums.size() - right;
                currCount -= combinationMap[nums[left]].second;
                combinationMap[nums[left]].first--;
                combinationMap[nums[left]].second = nChoosek(combinationMap[nums[left]].first, 2);
                currCount += combinationMap[nums[left]].second; //backtrack, puts back the updated contribution of the given key
                left++;
            }
        }
        return ans;
    }
};