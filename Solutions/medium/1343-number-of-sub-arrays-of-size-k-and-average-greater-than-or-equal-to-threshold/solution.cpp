class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;

        int sum = 0;
        for(int left = 0, right = 0; right < arr.size(); ++right){
            sum += arr[right];
            
            int size = right - left + 1;
            if(size > k){
                sum -= arr[left];
                ++left;
                --size;
            }
        
            if(size == k && sum / size >= threshold)
                ++ans;
        }

        return ans;
    }
};