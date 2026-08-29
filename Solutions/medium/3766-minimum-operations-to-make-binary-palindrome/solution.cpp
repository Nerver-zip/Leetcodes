class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        // pré-gerar palíndromos binários ≤ 5000
        vector<int> palins;
        for (int i = 1; i <= 5000; i++) {
            if (isBinaryPalindrome(i)) palins.push_back(i);
        }
        
        vector<int> ans;
        for (int n : nums) {
            int best = INT_MAX;
            for (int p : palins) {
                best = min(best, abs(p - n));
            }
            ans.push_back(best);
        }
        return ans;
    }
private:
    bool isBinaryPalindrome(int n) {
        string s = bitset<16>(n).to_string();
        s = s.substr(s.find('1')); // remove zeros à esquerda
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
    return true;
}

};