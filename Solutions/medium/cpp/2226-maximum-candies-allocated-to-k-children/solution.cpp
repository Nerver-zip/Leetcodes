class Solution {
private:
    void binarySearchMaxDivisor(const vector<int>& candies, int left, int right, long long k, int& ans){
        int mid = left + (right-left)/2;
        if (left <= right)
        {
            long long sum = 0;
            for (const auto& pile : candies)
            {
                sum += pile/mid;
                if(sum >= k) break;
            }
            if (sum >= k)
            {
                ans = mid;
                return binarySearchMaxDivisor(candies,mid+1,right,k, ans);
            }
            return binarySearchMaxDivisor(candies,left,mid-1,k,ans);
        }
        return;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (const auto& pile : candies)
            sum += pile;
        
        if (sum < k) return 0;
        sum /= k;

        int ans;
        binarySearchMaxDivisor(candies,1,sum,k, ans);
        return ans;
    }
};