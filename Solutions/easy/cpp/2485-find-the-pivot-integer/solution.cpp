class Solution {
public:
    int pivotInteger(int n) {
        int accum = 0;
        for (int i = 1; i <= n; ++i)
            accum += i;

        int curr = 0;
        while (n) {
            curr += n;

            if(curr == accum)
                return n;

            accum -= n;
            --n;
        }

        return -1;
    }
};
