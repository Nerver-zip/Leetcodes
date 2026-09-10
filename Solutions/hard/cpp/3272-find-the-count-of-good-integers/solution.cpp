using ll = long long;
class Solution {
public:
    int countGoodIntegers(int n, int k) {
        unordered_set<string> seen;
        vector<int> digits;
        int total = 0;
        
        function<void(int)> backtrack = [&](int idx) {
            if (idx == (n + 1) / 2) {
                vector<int> full = digits;
                for (int i = n / 2 - 1; i >= 0; --i)
                    full.push_back(digits[i]);

                if (full[0] == 0) return; // Leading zero

                ll num = vectorToNumber(full);
                if (num % k != 0) return;

                vector<int> freq(10, 0);
                for (int d : full) freq[d]++;

                string key = freqToString(freq);
                if (seen.count(key)) return;
                seen.insert(key);

                ll perms = countPermutations(freq, n);
                ll invalid = countLeadingZeroPermutations(freq, n);
                total += perms - invalid;
                return;
            }

            for (int d = 0; d <= 9; ++d) {
                if (idx == 0 && d == 0) continue; // skip leading zero
                digits.push_back(d);
                backtrack(idx + 1);
                digits.pop_back();
            }
        };

        backtrack(0);
        return total;
    }

private:
    ll vectorToNumber(const vector<int>& digits) {
        ll num = 0;
        for (int d : digits) num = num * 10 + d;
        return num;
    }

    string freqToString(const vector<int>& freq) {
        string s;
        for (int f : freq) s += to_string(f) + ",";
        return s;
    }

    ll countPermutations(const vector<int>& freq, int n) {
        ll res = factorial(n);
        for (int f : freq) res /= factorial(f);
        return res;
    }

    ll countLeadingZeroPermutations(vector<int> freq, int n) {
        if (freq[0] == 0) return 0;
        freq[0]--;
        ll res = factorial(n - 1);
        for (int f : freq) res /= factorial(f);
        return res;
    }

    unordered_map<int, ll> factMemo;
    ll factorial(int x) {
        if (x <= 1) return 1;
        if (factMemo.count(x)) return factMemo[x];
        return factMemo[x] = x * factorial(x - 1);
    }
};