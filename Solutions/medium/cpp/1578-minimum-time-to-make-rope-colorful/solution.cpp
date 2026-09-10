class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int maxTime = neededTime[0];

        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i - 1]) {
                // Remover o de menor tempo, manter o mais caro
                totalCost += min(neededTime[i], maxTime);
                maxTime = max(neededTime[i], maxTime);
            } else {
                maxTime = neededTime[i]; // reset maxTime para nova cor
            }
        }

        return totalCost;
    }
};