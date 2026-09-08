class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        long long sum = 0;
        int negCount = 0;
        int min = abs(matrix[0][0]);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                {
                    negCount++;
                }
                if (abs(matrix[i][j]) < min)
                {
                    min = abs(matrix[i][j]);
                }
            }
        }
        //if negative count is even we can transform all elements in the matrix to positive, thus returning the sum
        //if its odd we return the sum - min value * 2 (since it was counted towards the sum first)
        bool isEvenNegCount = negCount % 2 == 0 ? true : false;
        return isEvenNegCount ? sum : sum - min * 2;
    }
};