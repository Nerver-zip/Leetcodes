class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> seen;
        
        for (int i = 0; i < arr.size(); ++i) {
            int j = i - 1;
            int n = arr[i];
            while (j >= 0 && (arr[j]|n) != arr[j]) {
                seen.insert(arr[j]|n);
                arr[j] |= n; //expand subarr to the left
                --j;
            }
            seen.insert(arr[i]);
        }
        return seen.size();
    }
};