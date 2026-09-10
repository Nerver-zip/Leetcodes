int maxProfit(int *prices, int size);

int maxProfit(int *prices, int size){
    int lowest = prices[0];
    int profit;

    for (int i = 1; i < size; i++)
    {
        if (prices[i] < lowest)
        {
            lowest = prices[i];
        }
        else if(prices[i] - lowest > profit)
        {
            profit = prices[i] - lowest;
        }
    }
    return profit;
}