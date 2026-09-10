class Solution {
const int MOD = 1e9 + 7;
private:
    using Matrix = vector<vector<long long>>;
    Matrix multiply(const Matrix& a, const Matrix& b) {
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i){
            for (int k = 0; k < 26; ++k){
                if(a[i][k] == 0)
                    continue;
                for (int j = 0; j < 26; ++j)
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
        return result;
    }

    Matrix matrixPower(Matrix base, int power) {
        Matrix result(26, vector<long long>(26 , 0));
        for (int i = 0; i < 26; ++i)
            result[i][i] = 1;
        
        while (power > 0) {
            if (power % 2 == 1)
                result = multiply(result, base);
            base = multiply(base, base);
            power /= 2;
        }
        return result;
    }

    vector<long long> applyMatrix(const Matrix& M, const vector<long long>& V) {
        vector<long long> result(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                result[i] = (result[i] + M[i][j] * V[j]) % MOD;
            }
        }
        return result;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> V(26, 0);
        for (char c : s)
            V[c - 'a']++;

        Matrix T(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int next = (i + j) % 26;
                T[next][i]++;
            }
        }

        Matrix T_exp = matrixPower(T, t);

        vector<long long> V_final = applyMatrix(T_exp, V);

        long long total = 0;
            for (int i = 0; i < 26; ++i)
                total = (total + V_final[i]) % MOD;

        return total;
    }
};