class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        
        int ans = 0;
        for (int n : nums) {
            if(n > s.top()){
                ++ans;
                s.push(n);
            }
            
            while (!s.empty() && n < s.top()) {
                s.pop();
            }

            if(n > s.top()){
                ++ans;
                s.push(n);
            }
        }

        return ans;
    }
};