class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> stack;
        
        long long a, b, GCD = INT32_MIN;
        
        for (int n : nums) {
            stack.push(n);

            if(stack.size() > 1){
                a = stack.top();
                stack.pop();
                b = stack.top();
                GCD = gcd(a, b);
                stack.push(a);
            }

            while (stack.size() > 1 && GCD > 1) {
                stack.pop(); stack.pop();

                long long LCM = (a * b)/GCD;    
                stack.push(LCM);
                
                if(stack.size() > 1){
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    GCD = gcd(a, b);
                    stack.push(a);
                }
            }
        }

        int n = stack.size();
        vector<int> ans(n);
        while(!stack.empty()){
            ans[--n] = stack.top();
            stack.pop();
        }
        return ans;
    }
};
