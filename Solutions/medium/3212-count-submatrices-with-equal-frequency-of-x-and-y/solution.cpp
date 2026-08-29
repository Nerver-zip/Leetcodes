std::pair<int, int> operator+(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int,int>>> prefixCol(2, vector<pair<int,int>>(n, {0,0}));
        vector<pair<int,int>> prefixRow(n, {0,0});

        auto isFreqEqual = [](const pair<int,int>& p){
            return p.first && p.first == p.second;
        };

        int ans = 0;

        for(int i = 0; i < m; ++i){
            prefixRow[0] = {0,0};

            char c = grid[i][0];

            if(c == 'X') prefixRow[0].first++;
            else if(c == 'Y') prefixRow[0].second++;

            prefixCol[1][0] = prefixCol[0][0] + prefixRow[0];

            if(isFreqEqual(prefixCol[1][0]))
                ++ans;

            prefixCol[0][0] = prefixCol[1][0];

            for(int j = 1; j < n; ++j){
                c = grid[i][j];

                prefixRow[j] = prefixRow[j-1];

                if(c == 'X') prefixRow[j].first++;
                else if(c == 'Y') prefixRow[j].second++;

                prefixCol[1][j] = prefixCol[0][j] + prefixRow[j];

                if(isFreqEqual(prefixCol[1][j]))
                    ++ans;

                prefixCol[0][j] = prefixCol[1][j];
            }
        }

        return ans;
    }
};  