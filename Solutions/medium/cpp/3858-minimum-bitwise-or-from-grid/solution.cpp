class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        int maxv = 0;
        for(auto& row : grid)
            for(int x : row)
                maxv = max(maxv, x);

        int b = bit_width((unsigned)maxv);
        int mask = (1 << b) - 1;
        
        for(int shift = b-1; shift >= 0; --shift){
            int count = 0;
            int candidate = mask ^ (1 << shift);

            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j)
                    if((grid[i][j] | candidate) == candidate){
                        ++count;                  
                        break;
                    }
            }
            
            // Every row has a element which element | candidate doesnt grow candidate
            // which means we found a way to not set this bit
            if(count == m)
                mask = candidate;
        }

        return mask;
    }
};