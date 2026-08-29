class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) 
            return "0";

        string result;

        if ((numerator < 0) ^ (denominator < 0))
            result.push_back('-');

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // parte inteira
        result += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0) 
            return result; // exato

        result.push_back('.');
        unordered_map<long long, int> seen; //remainder -> position in the result where remainder was seen first
        
        //Input is guaranteed to generate output <= 1e4
        while (remainder != 0) {
            if (seen.count(remainder)) {
                result.insert(seen[remainder], "(");
                result.push_back(')');
                break;
            }
            seen[remainder] = result.size();

            remainder *= 10;
            result.push_back((remainder / d) + '0');
            remainder %= d;
        }
        return result;
    }        
};