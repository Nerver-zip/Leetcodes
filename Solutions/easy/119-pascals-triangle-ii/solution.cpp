class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> triangle;
        if(rowIndex == 0) return {1};

        for (int i = 0; i <= rowIndex; i++)
        {
            triangle.push_back({});
            for (int j = 0; j <= i ; j++)
            {
                if (j > 0 && j < i)
                    triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
                else
                    triangle[i].push_back(1);
            } 
        }
        std::vector<int> ans = triangle[rowIndex];
        return ans;
    }
};