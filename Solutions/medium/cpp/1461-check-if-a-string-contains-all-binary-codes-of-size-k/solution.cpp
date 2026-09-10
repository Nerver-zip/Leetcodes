using ll = long long;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.size();
        unordered_set<ll> substrings;
        
        PolyHash hash(k+1);

        for(int i = 0; i < n; ++i){
            hash.append(s[i]);
                    
            if(hash.size > k)
                hash.pop_front();

            if(hash.size == k)
                substrings.insert(hash.get());
        }

        return substrings.size() == (1 << k);
    }
private:
    struct PolyHash {
        constexpr static int MOD = 1'000'000'007;
        constexpr static int base = 0x10001;        

        using ll = long long;

        ll hash = 0;
        int size = 0;
        
        static inline std::vector<ll> powers;
        std::deque<int> chars;
        
        PolyHash(int maxSize){
            if ((int)powers.size() >= maxSize + 1) return;

            int old = powers.size();
            powers.resize(maxSize + 1);

            if (old == 0) {
                powers[0] = 1;
                old = 1;
            }

            for (int i = old; i <= maxSize; ++i) {
                powers[i] = (powers[i-1] * base) % MOD; 
            }
        }

        void append(char c){
            int cnum = c - '0' + 1;
            hash = (hash * base + cnum) % MOD;
            chars.push_back(cnum);
            ++size;
        }

        void prepend(char c){
            int cnum = c - '0' + 1;
            ll extra = (1LL * cnum * powers[size]) % MOD;
            hash = (hash + extra) % MOD;
            chars.push_front(cnum);
            ++size;
        }
        
        void pop_front(){
            if (size == 0) return;

            int front = chars.front();
            chars.pop_front();

            ll remove = (1LL * front * powers[size - 1]) % MOD;
            hash = (hash - remove + MOD) % MOD;

            --size;
        }

        ll get() const {
            return hash;
        }
    };
};