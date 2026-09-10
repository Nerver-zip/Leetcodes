class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        const int k = min(m, n) / 2; // max rhombus size

        set<int, greater<>> set;
        
        auto calc_rhombus = [&](int r, int c){
            for(int side = 1; side <= k; ++side){
                int sum = 0;
                
                // -> '\'
                int s = side, i = r, j = c;
                while(s--){
                    if(i < m && j < n){
                        sum += grid[i][j];
                        ++i;
                        ++j;

                        r = i;
                        c = j;
                    }
                    else
                        goto end;
                }

                // -> '/'
                if(isOutOfBounds(m, n, r, c)) break;

                s = side, i = r, j = c;
                while(s--){
                    if(i < m && j >= 0){
                        sum += grid[i][j];
                        ++i;
                        --j;

                        r = i;
                        c = j;

                    }
                    else
                        goto end;
                }

                // -> '\'
                if(isOutOfBounds(m, n, r, c)) break;

                s = side, i = r, j = c;
                while(s--){
                    if(i >= 0 && j >= 0){
                        sum += grid[i][j];
                        --i;
                        --j;

                        r = i;
                        c = j;
                    }
                    else
                        goto end;
                }

                // -> '/'
                if(isOutOfBounds(m, n, r, c)) break;

                s = side, i = r, j = c;
                while(s--){
                    if(i >= 0 && j < n){
                        sum += grid[i][j];
                        --i;
                        ++j;

                        r = i;
                        c = j;
                    }
                    else
                        goto end;
                }
                
                set.insert(sum);
                
                end:
            }
        };

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                set.insert(grid[i][j]); // area = 0
                calc_rhombus(i, j);    
            }
        }
        
        vector<int> ans;
        auto it = set.begin();
        while(ans.size() < 3 && it != set.end()){
            ans.push_back(*it);
            ++it;
        }

        return ans;
    }
private:
    bool isOutOfBounds(int m, int n, int r, int c){
        return m == r || n == c || r < 0 || c < 0;
    }
};