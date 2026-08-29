namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        std::unordered_map<int, std::vector<int>> directions = {
            {1, {0, 1}},  // right
            {2, {0, -1}}, // left
            {3, {1, 0}},  // up
            {4, {-1, 0}}, // down
        };

        int rows = grid.size();
        int columns = grid[0].size();
        
        std::unordered_map<std::pair<int, int>, int, std::hash<std::pair<int, int>>> minCost;
        minCost[{0, 0}] = 0; // Starting point cost

        std::deque<std::vector<int>> myDeque;
        myDeque.push_back({0, 0, 0}); // {row, column, cost}

        // Visited to avoid re-processing the same cell with the same or higher cost
        std::unordered_map<std::pair<int, int>, bool, std::hash<std::pair<int, int>>> visited;

        while (!myDeque.empty()) {
            std::vector<int> curr = myDeque.front();
            myDeque.pop_front();

            if (curr[0] == rows - 1 && curr[1] == columns - 1)
                return curr[2];  // If we reached the bottom-right cell

            // For each direction
            for (const auto& [d, coord] : directions) {
                std::vector<int> newPosition = {curr[0] + coord[0], curr[1] + coord[1]};
                int newCost = (d == grid[curr[0]][curr[1]]) ? curr[2] : curr[2] + 1;

                if (newPosition[0] < 0 || newPosition[0] >= rows || newPosition[1] < 0 || newPosition[1] >= columns)
                    continue;

                // Check if the new cost is better or if the cell has not been visited yet with the lower cost
                if (minCost.find({newPosition[0], newPosition[1]}) != minCost.end() && newCost >= minCost[{newPosition[0], newPosition[1]}]) 
                    continue;
                
                // Mark the new cell as visited
                if (visited.find({newPosition[0], newPosition[1]}) == visited.end() || newCost < minCost[{newPosition[0], newPosition[1]}]) {
                    minCost[{newPosition[0], newPosition[1]}] = newCost;
                    visited[{newPosition[0], newPosition[1]}] = true;

                    // Add to deque based on the cost
                    if (d == grid[curr[0]][curr[1]]) {
                        myDeque.push_front({newPosition[0], newPosition[1], newCost}); // Lower cost
                    } else {
                        myDeque.push_back({newPosition[0], newPosition[1], newCost}); // Higher cost
                    }
                }
            }
        }
        return 0;
    }
};
