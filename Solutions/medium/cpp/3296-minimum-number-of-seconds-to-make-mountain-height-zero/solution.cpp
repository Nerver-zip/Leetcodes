using ll = long long;
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll left = 0, right = 1e18, ans = 0;
        while(left <= right){
            ll mid = left + (right - left)/2;
            if(check(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ans;
    }
private:
    long long removed(long long T, int w) {
        long double val = 1.0L + (8.0L * (long double)T) / w;
        if (val < 0) return 0;
        long long x = (sqrtl(val) - 1) / 2;

        return x;
    }
    bool check(long long T, int H, vector<int>& w) {
        long long sum = 0;

        for (int t : w) {
            sum += removed(T, t);
            if (sum >= H) return true;
        }

        return false;
    }
};