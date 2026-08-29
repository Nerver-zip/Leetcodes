class Solution {
public:
    int romanToInt(std::string s) {
        int i = 0;
        int sum = 0;
        while (i < s.size())
        {
            if (s[i] == 'I')
            {
                if (s[i+1] == 'V' || s[i+1] == 'X')
                {
                    sum--;
                }
                else
                {
                    sum++; 
                }  
            }
            else if (s[i] == 'V')
            {
                sum = sum + 5;
            }
            else if (s[i] == 'X')
            {
                if (s[i+1] == 'L' || s[i+1] == 'C')
                {
                    sum = sum - 10;
                }
                else
                {
                    sum = sum + 10; 
                } 
            }
            else if (s[i] == 'L')
            {
                sum = sum + 50;
            }
            else if (s[i] == 'C')
            {
                if (s[i+1] == 'D' || s[i+1] == 'M')
                {
                    sum = sum - 100;
                }
                else
                {
                    sum = sum + 100; 
                } 
            }
            else if (s[i] == 'D')
            {
                sum = sum + 500;
            }
            else
            {
                sum = sum + 1000;
            }            
            i++;
        }
        return sum;
    }
};