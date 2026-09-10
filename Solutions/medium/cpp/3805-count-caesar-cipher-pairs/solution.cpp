using ll = long long;
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> freq;
        const int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            string key = buildKey(words[i]);
            ++freq[key];
        }
        
        ll ans = 0;

        for(const auto& [_, n] : freq){
            ans += nChoosek(n, 2);
        }
        
        return ans;
    }
private:
    
    string buildKey(const string& str){
        string key;
        
        for (int i = 1; i < str.size(); ++i){
            char c = (str[i] - str[i-1] + 26) % 26 + 'a';
            key.push_back(c);
        }

        return key;
    }

    ll nChoosek(ll n, ll k) {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;
        ll result = n;
        for( int i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
};