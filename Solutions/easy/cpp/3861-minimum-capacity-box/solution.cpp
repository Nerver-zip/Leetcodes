class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1;
        int cap = INT_MAX;
        for(int i = 0; i < capacity.size(); ++i){
            if(capacity[i] >= itemSize && capacity[i] < cap){
                idx = i;
                cap = capacity[i];
            }
        }

        return idx;
    }
};