class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        vector<int> rightMost;
        rightMost.reserve(n);

        for(const auto& row : grid){
            int pos = -1;
            for(int i = 0; i < n; ++i){
                if(row[i] == 1)
                    pos = i;
            }
            rightMost.push_back(pos);
        }
        
        // For each row, take the first that meets the requirement 
        // Proof of Soundness? Trust me bro
        // Maybe it works because we always start with the first row and it has the hardest requirement
        
        int swaps = 0;
        for(int i = 0; i < n; ++i){
            if(rightMost[i] > i){
                int idx = -1;
                
                for(int j = i; j < n; ++j){
                    if(rightMost[j] <= i){
                        idx = j;
                        break;
                    }
                }
                
                if(idx == -1)
                    return -1;
                 
                while(idx > i){
                    swap(rightMost[idx], rightMost[idx-1]);
                    ++swaps;
                    --idx;
                }
            }
        }

        return swaps;
    }
};