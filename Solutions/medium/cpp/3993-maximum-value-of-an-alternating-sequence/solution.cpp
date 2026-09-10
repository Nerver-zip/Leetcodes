class Solution {
public:
    long long maximumValue(int n, int s, int m) {        
        return max(1LL * s + (1LL * m * (n/2)) - ((n-1)/2), 
                   1LL * s + (1LL * m * (n/2)) - ((n-2)/2));
    }
};
