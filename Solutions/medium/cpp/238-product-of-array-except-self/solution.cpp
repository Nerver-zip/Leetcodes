class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix(n, 0); 
        vector<int> suffix(n, 0); 
        
        // Poderiamos modelar como:
        // prefix[i] = produto de 0 até i sem incluir nums[i]
        // suffix[i] = produto até n-1 até i sem incluir nums 
        // Ou, podemos usar o prefix anterior e fazer o produto com o prox suffix

        prefix[0] = nums[0];
        for(int i = 1; i < n; ++i)
            prefix[i] = prefix[i-1] * nums[i];

        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i)
            suffix[i] = suffix[i+1] * nums[i];

        vector<int> ans;
        ans.reserve(n);

        for(int i = 0; i < n; ++i){
            if(i == 0)
                ans.push_back(suffix[i+1]);
            else if(i == n-1)
                ans.push_back(prefix[i-1]);
            else
                ans.push_back(prefix[i-1] * suffix[i+1]);
            
        }
        
        return ans;
    }
};