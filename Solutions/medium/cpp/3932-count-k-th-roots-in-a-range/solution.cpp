using ll = long long;

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        ll y = l, n = 0;
        
        int ans = 0;

        if(k == 1){
            return r - l + 1;
        }
        
        while(y <= r){
            y = pow(n, k);
            ++n;

            if(y >= l && y <= r)
                ++ans;
        }

        return ans;
    }
};