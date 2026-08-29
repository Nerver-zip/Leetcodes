class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // 2, 3, 4, 5
        // 4, 5, 6, 7
        // 6, 7, 8, 9
        
        unordered_map<int, vector<int>> map;
        for(const auto& tuple : reservedSeats){
            int row = tuple[0], seat = tuple[1];
            map[row].push_back(seat);
        }

        int ans = 2 * (n - map.size());
        
        auto validate = [](const vector<int>& row, vector<int>& reserved, int assigns){
            if(assigns < 2){
                for(int s : reserved){
                    for(int x : row){
                        if(x == s)
                            return false;
                    }
                }
            }
            
            reserved.insert(reserved.end(), row.begin(), row.end());

            return true;
        };
        
        for(auto& [_, seats] : map){
            int res = 0;
            
            // 3 checks
            vector<int> row{2,3,4,5};
            res += validate(row, seats, res);

            row = {4,5,6,7};
            res += validate(row, seats, res);
            
            row = {6,7,8,9};
            res += validate(row, seats, res);

            ans += res; 
        }

        return ans;
    }
};