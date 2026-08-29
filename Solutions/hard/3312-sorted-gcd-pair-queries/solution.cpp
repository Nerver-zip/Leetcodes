class Solution {
public:
    vector<int> gcdValues(
        vector<int>& nums,
        vector<long long>& queries
    ) {
        const int maxValue = *max_element(nums.begin(), nums.end());

        vector<long long> frequency(maxValue + 1, 0);

        for (int value : nums) {
            frequency[value]++;
        }

        // exactGcd[d] = quantidade de pares cujo GCD é exatamente d.
        vector<long long> exactGcd(maxValue + 1, 0);

        for (int d = maxValue; d >= 1; --d) {
            long long divisibleCount = 0;

            // Conta quantos números são divisíveis por d.
            for (int multiple = d;
                 multiple <= maxValue;
                 multiple += d) {
                divisibleCount += frequency[multiple];
            }

            // Todos os pares em que ambos são divisíveis por d.
            exactGcd[d] =
                divisibleCount * (divisibleCount - 1) / 2;

            // Remove os pares cujo GCD é um múltiplo maior de d.
            for (int multiple = 2 * d;
                 multiple <= maxValue;
                 multiple += d) {
                exactGcd[d] -= exactGcd[multiple];
            }
        }

        // prefix[d] = número de pares com GCD <= d.
        vector<long long> prefix(maxValue + 1, 0);

        for (int d = 1; d <= maxValue; ++d) {
            prefix[d] = prefix[d - 1] + exactGcd[d];
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (long long query : queries) {
            // Primeiro d para o qual prefix[d] > query.
            int gcdValue = upper_bound(
                prefix.begin(),
                prefix.end(),
                query
            ) - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};