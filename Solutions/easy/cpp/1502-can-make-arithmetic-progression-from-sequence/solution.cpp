class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int diff = arr[0] - arr[1];

        for (int i = 2; i < arr.size(); ++i) {
            if(arr[i-1] - arr[i] != diff)
                return false;
        }

        return true;
    }
};