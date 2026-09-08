class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        
        int idx = INT32_MAX;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i-1] == arr[i])
                return false;
            if(arr[i-1] > arr[i])
            {
                idx = i;
                break;
            }
        }
        
        if(idx == INT32_MAX || idx == 1)
            return false;

        for(int i = idx; i < arr.size(); ++i){
            if(arr[i-1] == arr[i])
                return false;
            if(arr[i-1] < arr[i])
                return false;
        }

        return true;
    }
};