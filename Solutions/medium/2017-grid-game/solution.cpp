class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int SIZE = grid[0].size();

        std::vector<long long> firstPrefix(SIZE+1);
        std::vector<long long> secondPrefix(SIZE+1);

        firstPrefix[SIZE] = 0;
        secondPrefix[0] = 0;

        int j = SIZE-1;
        int k = 1;

        for (int i = 0; i < SIZE; i++)
        {
            firstPrefix[j] = grid[0][j] + firstPrefix[j+1];
            secondPrefix[k] = grid[1][i] + secondPrefix[k-1];
            j--;
            k++;
        }
        
        for (int i = 0; i < SIZE; i++)
        {
            //compare right route to down, secondPref[i+1] to adjust
            if (firstPrefix[i+1] < secondPrefix[i+1])
            {
                //once we go down with the first robot, return greatest from 
                //firstPref[i+1] and secondPref[i-1], if we reach the final position
                //of first prefix, then return secondPrefix[i]
                return std::max(firstPrefix[i+1],secondPrefix[i]);
            }
        }
        return -1; 
    }
};