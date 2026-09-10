using ll = long long;
class Solution {
public:
    string shortestPalindrome(string s) {
        const int n = s.size();

        PolyHash hash("", n), hash_rev("", n);
        int gpp = -1; // greatest palindrome prefix
        
        for (int i = 0; i < n; ++i) {
            hash.append(s[i]);
            hash_rev.prepend(s[i]);

            if(hash.get() == hash_rev.get()){
                gpp = i;
            }
        }
        
        // n - gpp - 1 = tamanho do sufixo fora do maior prefixo palíndromo
        // esse sufixo é copiado ao contrário e colocado na frente
        return string(s.rbegin(), s.rbegin() + (n - gpp - 1)) + s;
    }
private:
    
    struct PolyHash {
        static const ll M = 1000000007;
        static const ll P = 31; // Prime > 26 
        
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
};