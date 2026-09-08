class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles;
        int ans = numBottles;

        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            ++ans; ++emptyBottles; ++numExchange;
        }

        return ans;
    }
};