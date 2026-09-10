class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        
        for(int i = 0; i < customers.size(); ++i)
            if(!grumpy[i])
                ans += customers[i];
        
        int maxOffset = 0, offset = 0;

        // find window that can increase the ans the most
        for(int left = 0, right = 0; right < customers.size(); ++right){
            if(grumpy[right])
                offset += customers[right];
            
            if(right - left + 1 > minutes){
                if(grumpy[left]){
                    offset -= customers[left];
                }
                ++left;
            }

            maxOffset = max(maxOffset, offset);
        }

        return ans + maxOffset;
    }
};