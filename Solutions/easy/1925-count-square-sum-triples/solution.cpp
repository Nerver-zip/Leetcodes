class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> powers;

        for (int i = 1; i <= n; ++i)
            powers.insert(i*i);
        
        int ans = 0;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if(powers.count(i * i + j * j))
                    ++ans;
        return ans;

    }
};