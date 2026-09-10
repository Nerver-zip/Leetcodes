class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curr = 0;
        int ans = 0;

        for(int x : requests){
            ans += abs(curr - x);
            curr = x;
        }

        return ans;
    }
};