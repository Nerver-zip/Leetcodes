class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxInitVal = 0;
        int maxInitValIndex = 0;
        int maxFinalVal = 0;
        
        int j = 0;

        for (int i = 1; i < values.size(); i++)
        {
            if ((values[j] + j) > maxInitVal)
            {
                maxInitVal = values[j] + j;
                maxInitValIndex = j;
            }
            j++;
            if(maxInitVal + (values[i] - i) > maxFinalVal)
                maxFinalVal = maxInitVal + (values[i] - i);
        }
        return maxFinalVal;
    }
};