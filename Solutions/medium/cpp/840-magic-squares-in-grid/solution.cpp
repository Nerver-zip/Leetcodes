constexpr int magicSquares[8][3][3] = {
    {
        {8,1,6},
        {3,5,7},
        {4,9,2}
    },
    {
        {4,3,8},
        {9,5,1},
        {2,7,6}
    },
    {
        {2,9,4},
        {7,5,3},
        {6,1,8}
    },
    {
        {6,7,2},
        {1,5,9},
        {8,3,4}
    },
    {
        {6,1,8},
        {7,5,3},
        {2,9,4}
    },
    {
        {4,9,2},
        {3,5,7},
        {8,1,6}
    },
    {
        {8,3,4},
        {1,5,9},
        {6,7,2}
    },
    {
        {2,7,6},
        {9,5,1},
        {4,3,8}
    }
};

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        int res = 0;

        auto check = [&](int r, int c){
            int comb = 0;

        comb_loop:
            if (comb == 8) return;

            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    if (magicSquares[comb][i][j] != grid[r+i][c+j]) {
                        ++comb;
                        goto comb_loop;
                    }

            ++res;
            ++comb;
            goto comb_loop;
        };

        for (int i = 0; i < n-2;++i) {
            for (int j = 0; j < m-2; ++j) {
                check(i, j);
            }
        }

        return res;
    }
};