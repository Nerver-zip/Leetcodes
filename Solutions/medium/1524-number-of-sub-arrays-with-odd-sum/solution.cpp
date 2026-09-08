#define BOUND 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> prefix(arr.size()+1,0);
        long long even = 0;
        long long odd = 0;

        for (int i = 1; i < prefix.size(); i++)
        {
            prefix[i] = arr[i-1] + prefix[i-1];
        }

        for (int i = 0; i < prefix.size(); i++)
        {
            if (prefix[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        return (even * odd) % BOUND;
    }
};
