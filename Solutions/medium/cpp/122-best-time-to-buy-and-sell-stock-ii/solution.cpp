#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> myPrices(prices.size() + 2);
        myPrices[0] = INT32_MAX;
        myPrices[myPrices.size()-1] = INT32_MIN;

        for (int i = 0; i < prices.size(); ++i)
            myPrices[i+1] = prices[i];

        int profit = 0;
        
        //We want to buy bottoms and sell tops, the Holy Grail of trading
        //This essencialy works in a greedy way, we only buying if we can at least 
        //breakeven in the next day, always selling the day before a price drop if we are long
        int prev, curr, next, longPosition = -1;

        for (int i = 1; i < myPrices.size()-1; ++i)
        {
            prev = myPrices[i-1];
            curr = myPrices[i];
            next = myPrices[i+1];

            //a low is found
            if (longPosition == -1 && prev >= curr && curr <= next)
                longPosition = curr;

            //a high is found
            if (longPosition != -1 && prev <= curr && next <= curr)
            {
               profit += curr - longPosition;
               longPosition = -1;
            }
        }
        return profit;
    }
};