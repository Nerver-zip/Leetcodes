class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;

        string word(L, '?');
        vector<bool> fixed(L, false);

        // Step 1: Apply all 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: fill remaining with 'a'
        for (int i = 0; i < L; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // Step 3: fix 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool equal = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }

                if (equal) {
                    bool ok = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (fixed[pos]) continue;

                        char original = word[pos];

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == original) continue;

                            word[pos] = c;

                            // check if still valid (no T broken)
                            bool valid = true;

                            for (int k = max(0, pos - m + 1); k <= min(pos, n - 1); k++) {
                                if (str1[k] == 'T') {
                                    for (int t = 0; t < m; t++) {
                                        if (word[k + t] != str2[t]) {
                                            valid = false;
                                            break;
                                        }
                                    }
                                }
                                if (!valid) break;
                            }

                            if (valid) {
                                ok = true;
                                break;
                            }
                        }

                        if (ok) break;

                        word[pos] = original;
                    }

                    if (!ok) return "";
                }
            }
        }

        return word;
    }
};