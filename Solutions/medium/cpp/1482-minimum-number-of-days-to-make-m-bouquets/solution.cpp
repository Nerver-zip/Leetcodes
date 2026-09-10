class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int size = bloomDay.size();
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        // Sliding window of size k, that need to be valid at least m times
        auto canCollect = [&](int limit){
            int validWindows = 0;
            int collected = 0;

            for (int right = 0, left = 0; right < size; ++right) {
                if(bloomDay[right] <= limit)
                    ++collected;
                
                if(right - left + 1 > k){
                    if(bloomDay[left] <= limit)
                        --collected;
                    ++left;
                }

                if(collected == k){
                    ++validWindows;
                    left = right+1; // to make left = right by the next iteration
                    collected = 0;
                }
            }

            return validWindows >= m;
        };

        int low = 0;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high-low)/2;

            if(canCollect(mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};