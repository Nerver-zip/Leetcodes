class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        const vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        auto bfs = [&](vector<vector<bool>>& visited, queue<pair<int,int>>& q){
            while(!q.empty()){
                auto [r,c] = q.front(); q.pop();
                for(auto [dr,dc] : directions){
                    int nr = r + dr, nc = c + dc;
                    if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue;
                    if(visited[nr][nc]) continue;
                    if(heights[nr][nc] < heights[r][c]) continue;
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        };

        queue<pair<int,int>> q;
        for(int i=0;i<ROWS;i++){
            pacific[i][0]=true; q.push({i,0});
        }
        for(int j=0;j<COLS;j++){
            pacific[0][j]=true; q.push({0,j});
        }
        bfs(pacific, q);

        for(int i=0;i<ROWS;i++){
            atlantic[i][COLS-1]=true; q.push({i,COLS-1});
        }
        for(int j=0;j<COLS;j++){
            atlantic[ROWS-1][j]=true; q.push({ROWS-1,j});
        }
        bfs(atlantic, q);

        vector<vector<int>> ans;
        for(int i=0;i<ROWS;i++)
            for(int j=0;j<COLS;j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
        return ans;
    }
};