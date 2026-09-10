class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int remainder = 0;

        while (numBottles) {
            ans += numBottles;
            remainder += numBottles % numExchange;
            numBottles /= numExchange;

            if(remainder >= numExchange){
                remainder -= numExchange;
                ++numBottles;
            }
        }

        return ans;
    }
};