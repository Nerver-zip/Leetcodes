class Solution {
private:
    int binarySearch(long long x, long long left, long long right, long long& ans){
        if (left <= right)
        {
            long long mid = left + (right-left)/2;
            if (mid * mid == x)
                return mid;
            if (mid * mid < x)
            {
                ans = mid;
                return binarySearch(x, mid+1, right, ans);
            }
            return binarySearch(x, left, mid-1, ans);
        }
        return ans;
    }
public:
    int mySqrt(int x) {
        long long y = 0;
        return binarySearch(x, 0, x, y);
    }
};