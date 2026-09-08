struct Compare {
    bool operator()(const string& a, const string& b) {
        return a > b;
    }
};

class Solution {
private:

    std::priority_queue<string,vector<string>,Compare> permutations;

    void generatePermutations(string& digits, int index){
        if (index == digits.size())
        {
            permutations.push(digits);
        }
        for (int i = index; i < digits.size(); i++)
        {
            std::swap(digits[index],digits[i]);
            generatePermutations(digits,index+1);
            std::swap(digits[index], digits[i]);
        }
        return;
    }

    string validate(string pattern){
        bool validated = true;
        while (!permutations.empty())
        {
            string curr = permutations.top();
            
            for (int i = 0; i < curr.size(); i++)
            {
                if (pattern[i] == 'I' && curr[i] > curr[i + 1])
                {
                    validated = false;
                    break;
                }   
                if (pattern[i] == 'D' && curr[i] < curr[i + 1])
                {
                    validated = false;
                    break;
                }
            }
            if(validated)
                return curr;
            validated = true;
            permutations.pop();
        }
        return "";
    }
public:
    string smallestNumber(string pattern) {

        string digits;

        for (int i = 1; i <= pattern.size()+1; i++)
        {
            digits += std::to_string(i);
        }

        generatePermutations(digits,0);
        string ans = validate(pattern);
        return ans;
    }
};