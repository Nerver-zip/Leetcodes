class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::queue<std::pair<int,int>> serverQueue;

        vector<int> serverNumROW(ROWS,0);
        vector<int> serverNumCOL(COLS,0);

    int ans = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
            {
                serverNumROW[i]++;
                serverNumCOL[j]++;
                serverQueue.push({i,j});
            }
        }
    }

    while (!serverQueue.empty())
    {        
        if (serverNumROW[serverQueue.front().first] > 1 || serverNumCOL[serverQueue.front().second] > 1)
        {
            ans++;
        }
        serverQueue.pop();
    }
    return ans;
    }
};