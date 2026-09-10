struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums2Map;
        int size = nums1.size();
        for (int i = 0; i < size; i++)
            nums2Map[nums2[i]] = i;
        
        vector<int> nums1Mapped(size);
        for (int i = 0; i < size; i++)
            nums1Mapped[i] = nums2Map[nums1[i]];
        
        FenwickTreeOneBasedIndexing bitLeft(size);
        vector<int> countLeft(size);
        for (int i = 0; i < size; i++)
        {
            countLeft[i] = bitLeft.sum(nums1Mapped[i] - 1);
            bitLeft.add(nums1Mapped[i],1);
        }

        FenwickTreeOneBasedIndexing bitRight(size);
        vector<int> countRight(size);
        for (int i = size-1; i >= 0; i--)
        {
            countRight[i] = bitRight.sum(size - 1) - bitRight.sum(nums1Mapped[i]);
            bitRight.add(nums1Mapped[i], 1);
        }
        
        long long total = 0;

        for (int i = 0; i < size; i++)
            total += (long long) countLeft[i] * countRight[i];
        return total;
    }
};