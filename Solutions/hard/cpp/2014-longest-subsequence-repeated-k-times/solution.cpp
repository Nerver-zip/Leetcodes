class Solution {
private:
    bool isKRepeatedSubsequence(const string& seq, const string& s, int k) {
        int i = 0, j = 0, count = 0;
        while (j < s.size()) {
            if (s[j] == seq[i]) {
                ++i;
                if (i == seq.size()) {
                    i = 0;
                    ++count;
                    if (count == k) return true;
                }
            }
            ++j;
        }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Só usamos letras com frequência >= k
        string valid_chars;
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k) valid_chars += c;
        }

        queue<string> q;
        string best = "";

        // Começa com todas letras válidas
        for (char c : valid_chars) {
            string start(1, c);
            q.push(start);
        }

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isKRepeatedSubsequence(curr, s, k)) {
                if (curr.size() > best.size() || (curr.size() == best.size() && curr > best)) {
                    best = curr;
                }

                // Tenta expandir para strings maiores
                if (curr.size() < 7) {
                    for (char c : valid_chars) {
                        q.push(curr + c);
                    }
                }
            }
        }
        return best;
    }
};
