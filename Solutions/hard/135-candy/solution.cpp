class Solution {
public:
    int candy(vector<int>& ratings) {
        const int size = ratings.size();
        vector<int> candies(size, 1);

        for (int i = 1; i < size; ++i)
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        
        for (int i = size-2; i >= 0; --i)
            if(ratings[i] > ratings[i+1])
                if(candies[i] <= candies[i+1])
                    candies[i] = candies[i+1] + 1;
        
        int sum = 0;

        for (int candy : candies)
            sum += candy;
        
        return sum;       
    }
};