class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix;

        for(int n : arr1){
            while(n){
                prefix.insert(n);
                n /= 10;
            }
        }

        auto digitCount = [](int n){
            int count = n == 0 ? 1 : 0;
            while(n){
                n /= 10;
                ++count;
            }
            return count;
        };

        int ans = 0;
        for(int n : arr2){
            while(n){
                if(prefix.count(n)){
                    ans = max(ans, digitCount(n));
                    break;
                }
                n /= 10;
            }
        }
        
        return ans;
    }
};