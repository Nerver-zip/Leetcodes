class Solution {
    static constexpr long long LIMIT = 1'000'001;

    // Retorna min(C(n, r), LIMIT).
    long long combination(int n, int r) {
        r = min(r, n - r);

        long long result = 1;

        for (int i = 1; i <= r; ++i) {
            result = result * (n - i + 1) / i;

            if (result >= LIMIT)
                return LIMIT;
        }

        return result;
    }

    // Número de permutações distintas do multiconjunto.
    //
    // total! / (freq[0]! * freq[1]! * ...)
    //
    // Calculado como produto de combinações:
    // C(total, f0) * C(total-f0, f1) * ...
    long long countPermutations(const array<int, 26>& freq) {
        int remaining = 0;

        for (int amount : freq)
            remaining += amount;

        long long ways = 1;

        for (int amount : freq) {
            if (amount == 0)
                continue;

            long long choose = combination(remaining, amount);

            ways *= choose;

            if (ways >= LIMIT)
                return LIMIT;

            remaining -= amount;
        }

        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        array<int, 26> count{};

        for (char c : s)
            ++count[c - 'a'];

        array<int, 26> half{};
        char middle = '\0';
        int halfLength = 0;

        for (int c = 0; c < 26; ++c) {
            half[c] = count[c] / 2;
            halfLength += half[c];

            if (count[c] % 2 == 1)
                middle = static_cast<char>('a' + c);
        }

        if (countPermutations(half) < k)
            return "";

        string left;
        left.reserve(halfLength);

        for (int position = 0; position < halfLength; ++position) {
            for (int c = 0; c < 26; ++c) {
                if (half[c] == 0)
                    continue;

                // Tenta colocar esta letra na posição atual.
                --half[c];

                long long ways = countPermutations(half);

                if (k > ways) {
                    // A resposta não está neste bloco.
                    k -= static_cast<int>(ways);
                    ++half[c];
                } else {
                    // A resposta está neste bloco.
                    left.push_back(static_cast<char>('a' + c));
                    break;
                }
            }
        }

        string right(left.rbegin(), left.rend());

        if (middle != '\0')
            return left + middle + right;

        return left + right;
    }
};