using ll = long long;
class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
            PolyHash h(n);

        for (char c : s)
            h.append(c);

        long long ans = n; // s vs s

        for (int i = 1; i < n; i++) {
            int lo = 0, hi = n - i;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (h.get(0, mid) == h.get(i, i + mid))
                    lo = mid;
                else
                    hi = mid - 1;
            }
            ans += lo;
        }
        return ans;
    }
private:
    struct PolyHash {
        constexpr static int MOD = 1'000'000'007;
        constexpr static int base = 0x10001;
    
        int size = 0;

        static inline vector<ll> powers;
        vector<long long> pref;
        
        PolyHash(int size){
            pref.reserve(size + 1);
            pref.push_back(0);

            if(powers.size() == size + 1)
                return;
            
            powers.resize(size + 1);
            powers[0] = 1;

            for(int i = 1; i <= size; ++i)
                powers[i] = (powers[i-1] * base) % MOD; 
        }

        void append(char c){
            int cnum = c - 'a' + 1;
            pref.push_back((pref.back() * base + cnum) % MOD);
            ++size;
        }

        // Substring hash [l, r)
        long long get(int l, int r) const {
            return (pref[r] - pref[l] * powers[r - l] % MOD + MOD) % MOD;
        }
    };
};