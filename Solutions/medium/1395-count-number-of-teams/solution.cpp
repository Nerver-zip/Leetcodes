struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int n) : n(n), bit(n+1) {}

    void add(int idx, int delta){
        while(idx <= n){
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int prefix(int idx) const {
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx & -idx;
        }
        
        return sum;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int n = rating.size();

        vector<int> sorted = rating;
        
        ranges::sort(sorted);

        auto rank = [&](int x){
            return ranges::lower_bound(sorted, x) - sorted.begin() + 1;
        };
        
        FenwickTree left(n), right(n);
        
        for(int x : rating){
            right.add(rank(x), 1);
        }

        int ans = 0;

        for (int j = 0; j < n; ++j) {
            int x = rank(rating[j]);

            right.add(x, -1);

            int leftSmaller = left.prefix(x - 1);
            int leftGreater = j - left.prefix(x);

            int rightCount = n - j - 1;

            int rightSmaller = right.prefix(x - 1);
            int rightGreater = rightCount - right.prefix(x);

            ans += leftSmaller * rightGreater
                 + leftGreater * rightSmaller;

            left.add(x, 1);
        }

        return ans;
    }
};