using min_heap = priority_queue<int, vector<int>, std::greater<>>; //val, i, j 
using max_heap = priority_queue<int>; 

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int size = grid.size();

        //Ascending
        for (int r = 0; r < size; ++r) {
            max_heap pq;
            int currRow = r;
            int currCol = 0;

            while (currRow < size && currCol < size) { 
                pq.push(grid[currRow][currCol]);
                ++currRow;
                ++currCol;
            }
            currRow = r;
            currCol = 0;
            while (!pq.empty()) {
                grid[currRow][currCol] = pq.top();
                pq.pop();
                ++currRow;
                ++currCol;
            }
        }

        //Descending
        for (int c = 1; c < size; ++c) {
            min_heap pq;
            int currCol = c;
            int currRow = 0;

            while (currRow < size && currCol < size) { 
                pq.push(grid[currRow][currCol]);
                ++currRow;
                ++currCol;
            }
            currCol = c;
            currRow = 0;
            while (!pq.empty()) {
                grid[currRow][currCol] = pq.top();
                pq.pop();
                ++currRow;
                ++currCol;
            }
        }
        return grid;
    }
};