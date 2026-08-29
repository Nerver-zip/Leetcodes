class Solution {
private:
    int countForOne(const vector<int>& nums2, long long a, long long x) {
        int left = 0, right = nums2.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((a >= 0 && nums2[mid] * a <= x) || 
                (a < 0 && nums2[mid] * a > x)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return a >= 0 ? left : nums2.size() - left;
    }

    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long x) {
        long long count = 0;
        for (long long a : nums1) {
            count += countForOne(nums2, a, x);
        }
        return count;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};