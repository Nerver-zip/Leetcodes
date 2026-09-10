class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        auto rotate = [](vector<int>& arr)->void{
            int back = arr.back();
            int prev = arr.front();
            for(int i = 1; i < arr.size(); ++i){
                int temp = arr[i];
                arr[i] = prev;
                prev = temp;
            }

            arr.front() = back;
        };

        auto rotateCol = [&]()->void{
            int n = grid.size();
            int back = grid[n-1][0];
            int prev = grid[0][0];
            
            for(int i = 1; i < n; ++i){
                int temp = grid[i][0];
                grid[i][0] = prev;
                prev = temp;
            }

            grid[0][0] = back;
        };

        for(int i = 0; i < k; ++i){
            for(auto& row : grid){
                rotate(row);
            }
            rotateCol();
        }
        
        
        return grid;
    }
};