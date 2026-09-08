class Solution {
public:
    int minOperations(string s) {
        const int n = s.size();
        
        deque<char> dq(s.begin(), s.end());
        int ans = numeric_limits<int>::max();

        for(int r = 0; r < n; ++r){
            int res = 0;
            string target;
            int i = n & 1 ? n/2 + 1 : n/2;
            int end = n & 1 ? i - 2 : i-1; 
            
            for(; i < dq.size(); ++i){
                target += dq[i];
            }
            
            int left = 0, right = target.size()-1;
            for(int i = 0; i <= end; ++i){
                res += min(abs(target[right] - dq[left]), 26 - abs(target[right] - dq[left]));
                --right;
                ++left;
            }
            
        
            dq.push_back(dq.front());
            dq.pop_front();
            
            ans = min(res + r, ans);
        }

        return ans;
    }
};