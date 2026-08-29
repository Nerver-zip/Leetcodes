class Fancy {
public:
    const int MOD = 1e9 + 7;  // Modulo value
    vector<long long> val;    // Store the adjusted values
    long long a, b;           // a = multiplicative factor, b = additive factor

    Fancy() {
        a = 1;  // Initial multiplicative factor
        b = 0;  // Initial additive factor
    }

    // Append a new value to the Fancy object
    void append(int val) {
        // Adjust the value and store it after inverse-modulo multiplication
        long long x = (val - b + MOD) % MOD;
        this->val.push_back(x * modInverse(a) % MOD);
    }

    // Add a value to all elements
    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    // Multiply all elements by m
    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    // Get the value at index idx
    int getIndex(int idx) {
        if (idx >= val.size()) return -1;
        return (a * val[idx] + b) % MOD;
    }

private:
    // Function to calculate modular inverse using Fermat's Little Theorem
    long long modInverse(long long x) {
        long long result = 1;
        long long power = MOD - 2;  // Since MOD is prime, a^(MOD-2) % MOD is the inverse
        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            power /= 2;
        }
        return result;
    }
};