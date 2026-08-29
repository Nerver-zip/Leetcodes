class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        vector<int> ans;
        std::unordered_map<int,int> ballColorMap; //uses a ball as key to search for a color
        std::unordered_map<int,int> colorMap; //Frequency of color

        for (int i = 0; i < queries.size(); i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            int currBallColor = ballColorMap[ball];
            colorMap[color]++;

            if (currBallColor != 0)
            {
               colorMap[currBallColor] > 1 ? colorMap[currBallColor]-- : colorMap.erase(currBallColor);
            }
            
            ballColorMap[ball] = color;
            ans.push_back(colorMap.size());
        } 
        return ans;
    }
};