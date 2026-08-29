class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;

                long long v = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;

                    C[i][j] = (C[i][j] + v * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix matPow(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp > 0) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1)
            return m;

        int S = 2 * m;

        // states:
        // 0..m-1     => last move DOWN, current value x
        // m..2m-1    => last move UP, current value x

        Matrix T(S, vector<long long>(S, 0));

        for (int x = 0; x < m; x++) {

            // last was UP, next must go DOWN
            for (int y = 0; y < x; y++) {
                T[m + x][y] = 1;
            }

            // last was DOWN, next must go UP
            for (int y = x + 1; y < m; y++) {
                T[x][m + y] = 1;
            }
        }

        // Initial vector for arrays of length 2
        vector<long long> init(S, 0);

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a < b) {
                    // last move UP, current value b
                    init[m + b]++;
                }
                else if (a > b) {
                    // last move DOWN, current value b
                    init[b]++;
                }
            }
        }

        Matrix P = matPow(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int j = 0; j < S; j++) {
            for (int k = 0; k < S; k++) {
                finalState[j] =
                    (finalState[j] + init[k] * P[k][j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : finalState)
            ans = (ans + x) % MOD;

        return ans;
    }
};