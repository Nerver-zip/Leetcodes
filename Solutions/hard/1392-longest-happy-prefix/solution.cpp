using ll = long long;

class Solution {
public:
    string longestPrefix(string s) {
        const int size = s.size();
        int prefix_i = -1; // longest common prefix up to i
        
        PolyHash prefix(size), suffix(size);

        for(int i = 0, j = size-1; i < size-1; ++i, --j){
            prefix.append(s[i]);
            suffix.prepend(s[j]);

            if(prefix.get() == suffix.get())
                prefix_i = i;
        }

        return string(s.begin(), s.begin() + prefix_i + 1);
    }
private:
    struct PolyHash {
        constexpr static int MOD = 1'000'000'007;
        constexpr static int base = 0x10001;        

        ll hash = 0;
        int size = 0;
        
        static inline vector<ll> powers;
        
        PolyHash(int size){
            if(powers.size() == size + 1) return;
            
            powers.resize(size + 1);
            powers[0] = 1;
            for (int i = 1; i <= size; ++i) {
                powers[i] = (powers[i-1] * base) % MOD; 
            }
        }

        void append(char c){
            int cnum = c - 'a' + 1;
            hash = (hash * base + cnum) % MOD;  
            ++size;
        }

        void prepend(char c){
            int cnum = c - 'a' + 1;
            ll extra = (cnum * powers[size]) % MOD;
            hash = (hash + extra) % MOD;
            ++size;
        }

        int get() const {
            return hash;
        }
    };
};