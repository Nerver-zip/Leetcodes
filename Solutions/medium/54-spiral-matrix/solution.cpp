class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int SIZE = ROWS * COLS;
        
        vector<int> ans;
        
        int i = 0;
        int j = 0;

        int leftBound = 0;
        int upBound = 0;
        int rightBound = COLS-1;
        int downBound = ROWS-1;

        //Right, down, left, up, repeat
        while (ans.size() < SIZE)
        {
            //As far right as possible
            for (j = leftBound, i = upBound; j <= rightBound && ans.size() < SIZE; j++)
            {
                ans.push_back(matrix[i][j]);
            }
            //As far down as possible
            for (i = ++upBound, j = rightBound; i <= downBound && ans.size() < SIZE; i++)
            {
                ans.push_back(matrix[i][j]);
            }
            //As far left as possible
            for (j = --rightBound, i = downBound; j >= leftBound && ans.size() < SIZE; j--)
            {
                ans.push_back(matrix[i][j]);
            }
            //As far up as possible
            for (i = --downBound, j = leftBound++; i >= upBound && ans.size() < SIZE; i--)
            {
                ans.push_back(matrix[i][j]);
            }        
        }
        return ans;
    }
};