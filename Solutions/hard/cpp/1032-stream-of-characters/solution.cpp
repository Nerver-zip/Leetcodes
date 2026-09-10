class StreamChecker {
using ll = long long;
public:
    StreamChecker(vector<string>& words) : queryHash("", 1e4) {
        maxLen = 0;
        
        for(const auto& word : words){
            int len = word.size();
            maxLen = max(maxLen, len);
            hashesByLen[len].insert(PolyHash(word, 200).get());
        }
    }
    
    bool query(char letter) {
        queryHash.append(letter);
        
        int right = queryHash.size;

        // só testa tamanhos relevantes
        for (auto& [len, hset] : hashesByLen) {
            if (len > right) continue;
            
            if(hset.count(queryHash.get(right - len, right)))
                return true;
        }
        
        return false;
    }

private:
    unordered_map<int, unordered_set<ll>> hashesByLen;
    int maxLen;
    
    struct PolyHashPrefix {
        constexpr static int MOD = 1'000'000'007;
        constexpr static int base = 0x10001;
    
        int size = 0;

        static inline vector<ll> powers;
        vector<long long> pref;
        
        PolyHashPrefix(const string& s, int size){
            pref.reserve(size + 1);
            pref.push_back(0);

            if(powers.size() != size + 1){
                powers.resize(size + 1);
                powers[0] = 1;

                for(int i = 1; i <= size; ++i)
                    powers[i] = (powers[i-1] * base) % MOD; 
            }

            for(const auto& c : s)
                this->append(c);
        }

        void append(char c){
            int cnum = c - 'a' + 1;
            pref.push_back((pref.back() * base + cnum) % MOD);
            ++size;
        }
        
        int getSize() const {
            return this->size;
        }

        // Substring hash [l, r)
        long long get(int l, int r) const {
            return (pref[r] - pref[l] * powers[r - l] % MOD + MOD) % MOD;
        }
    };

    
    struct PolyHash {
        static const ll M = 1000000007;
        static const ll P = 0x10001; 
        
        inline static std::vector<ll> powers;
        
        ll hash = 0;
        int size = 0;

        PolyHash(const std::string& s = "", int maxSize = 0) {
            if(powers.size() < maxSize){
                powers.resize(maxSize + 1);
            
                powers[0] = 1;
                for (int i = 1; i <= maxSize; i++) 
                    powers[i] = (powers[i - 1] * P) % M;
            }

            for (char c : s) 
                append(c);
        }

        void append(char c) {
            ll val = c - 'a' + 1;
            hash = (hash * P + val) % M;
            size++;
        }

        void prepend(char c) {
            ll val = c - 'a' + 1;
            ll weight = powers[size];
            ll extra = (val * weight) % M;
            hash = (extra + hash) % M;
            size++;
        }

        ll get() const { 
            return hash; 
        }
    };
    
    PolyHashPrefix queryHash;
};