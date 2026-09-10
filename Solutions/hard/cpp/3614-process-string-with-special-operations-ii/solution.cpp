class Solution {
public:
    char processStr(string s, long long k) {
        const long long INF = 4e18;

        int n = (int)s.size();
        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                cur = min(INF, cur + 1);
            }
            else if (c == '*') {
                if (cur > 0) cur--;
            }
            else if (c == '#') {
                cur = min(INF, cur * 2);
            }
            // tamanho não muda

            len[i] = cur;
        }

        if (k < 0 || k >= cur) return '.';

        long long pos = k;

        for (int i = n - 1; i >= 0; i--) {
            char op = s[i];
            long long prevLen = (i == 0 ? 0 : len[i - 1]);
            long long curLen  = len[i];

            if ('a' <= op && op <= 'z') {
                if (pos == curLen - 1) {
                    return op;
                }
            }
            else if (op == '#') {
                if (prevLen > 0) {
                    pos %= prevLen;
                }
            }
            else if (op == '%') {
                if (prevLen > 0) {
                    pos = prevLen - 1 - pos;
                }
            }
            // índices preservados
        }

        return '.';
    }
};